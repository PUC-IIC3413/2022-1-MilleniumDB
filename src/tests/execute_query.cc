#include <chrono>
#include <fstream>
#include <iostream>

#include <boost/program_options.hpp>

#include "base/exceptions.h"
#include "base/binding/binding_iter.h"
#include "base/exceptions.h"
#include "parser/query/query_parser.h"
#include "base/thread/thread_key.h"
#include "query_optimizer/quad_model/quad_model.h"
#include "storage/buffer_manager.h"
#include "storage/file_manager.h"

using namespace std;
namespace po = boost::program_options;


void execute_query(const std::string& query) {
    unique_ptr<BindingIter> physical_plan;
    ThreadInfo thread_info(chrono::system_clock::now()); // timeout is not considered in this test

    // start timer
    auto start = chrono::system_clock::now();
    try {
        auto logical_plan = QueryParser::get_query_plan(query);
        physical_plan = quad_model.exec(*logical_plan, &thread_info);
    }
    catch (const QueryException& e) {
        cout << "---------------------------------------\n";
        cout << "Query Exception: " << e.what() << "\n";
        cout << "---------------------------------------\n";
        return;
    }
    catch (const LogicException& e) {
        cout << "---------------------------------------\n";
        cout << "Logic Exception: " << e.what() << "\n";
        cout << "---------------------------------------\n";
        return;
    }
    chrono::duration<float, std::milli> parser_duration = chrono::system_clock::now() - start;
    uint64_t result_count = 0;
    auto execution_start = chrono::system_clock::now();
    try {
        physical_plan->begin(cout);

        // get all results
        while (physical_plan->next()) {
            result_count++;
        }

        chrono::duration<float, std::milli> execution_duration = chrono::system_clock::now() - execution_start;

        // print execution stats in server console
        cout << "\nPlan Executed:\n";
        physical_plan->analyze(cout, 2);
        cout << "\nResults:" << result_count << "\n";

        // write execution stats in output stream
        cout << "---------------------------------------\n";
        cout << "Found " << result_count << " results.\n";
        cout << "Execution time: " << execution_duration.count() << " ms.\n";
        cout << "Query Parser/Optimizer time: " << parser_duration.count() << " ms.\n";
    }
    catch (const LogicException& e) {
        cout << "---------------------------------------\n";
        cout << "LogicException:" << e.what() << endl;
    }
    catch (...) {
        std::cerr << "Unknown exception." << endl;
    }
}


int main(int argc, char **argv) {
    int shared_buffer_size;
    int private_buffer_size;
    string db_folder;

    try {
        // Parse arguments
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "show this help message")
            ("db-folder,d", po::value<string>(&db_folder)->required(), "set database folder path")
            (
                "buffer-size,b",
                po::value<int>(&shared_buffer_size)->default_value(BufferManager::DEFAULT_SHARED_BUFFER_POOL_SIZE),
                "set shared buffer pool size"
            )
            (
                "private-buffer-size,",
                po::value<int>(&private_buffer_size)->default_value(BufferManager::DEFAULT_PRIVATE_BUFFER_POOL_SIZE),
                "set private buffer pool size for each thread"
            )
        ;

        po::positional_options_description p;
        p.add("db-folder", -1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);

        if (vm.count("help")) {
            cout << "Usage: server [options] DB_FOLDER\n";
            cout << desc << "\n";
            return 0;
        }
        po::notify(vm);

        // Validate params
        if (shared_buffer_size < 0) {
            cerr << "Buffer size cannot be a negative number.\n";
            return 1;
        }

        if (private_buffer_size < 0) {
            cerr << "Private buffer size cannot be a negative number.\n";
            return 1;
        }

        // Initialize model
        auto model_destroyer = QuadModel::init(db_folder, shared_buffer_size, private_buffer_size, 1);

        cout << "Initializing server...\n";
        quad_model.catalog().print();

        stringstream str_stream;
        str_stream << std::cin.rdbuf();
        string query = str_stream.str();

        execute_query(query);
    }
    catch (exception& e) {
        cerr << "Exception: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        cerr << "Exception of unknown type!\n";
        return 1;
    }
    return 0;
}
