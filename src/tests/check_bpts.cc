#include <experimental/filesystem>
#include <fstream>
#include <iostream>

#include <boost/program_options.hpp>

#include "query_optimizer/quad_model/quad_model.h"
#include "storage/buffer_manager.h"
#include "storage/index/bplus_tree/bplus_tree.h"

using namespace std;
namespace po = boost::program_options;

template <std::size_t N>
void check(const string& name, BPlusTree<N>& bpt) {
    std::cout << "Checking " << name << ":\n";

    if (bpt.check()) {
        std::cout << "  Good\n";
    }
}

int main(int argc, char **argv) {
    string db_folder;
    int buffer_size;

    // Parse arguments
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "show this help message")
        ("buffer-size,b", po::value<int>(&buffer_size)->default_value(BufferManager::DEFAULT_SHARED_BUFFER_POOL_SIZE),
                "set shared buffer pool size")
        ("db-folder,d", po::value<string>(&db_folder)->required(), "set database folder path")
    ;

    po::positional_options_description p;
    p.add("db-folder", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);

    if (vm.count("help")) {
        cout << "Usage: check_btps ./path/to/db-folder [OPTIONS]\n";
        cout << desc << "\n";
        return 0;
    }
    po::notify(vm);

    { // check if db_folder is empty or does not exists
        namespace fs = std::experimental::filesystem;
        if (!fs::exists(db_folder) ) {
            cerr << "Database folder doesn't exists.\n";
            return 1;
        } else if (fs::is_empty(db_folder)) {
            cerr << "Database folder is empty.\n";
            return 1;
        }
    }

    auto model_destroyer = QuadModel::init(db_folder, buffer_size, 0, 0);

    check("node_label", *quad_model.node_label);
    check("label_node", *quad_model.label_node);

    check("object_key_value", *quad_model.object_key_value);
    check("key_value_object", *quad_model.key_value_object);

    check("from_to_type_edge", *quad_model.from_to_type_edge);
    check("to_type_from_edge", *quad_model.to_type_from_edge);
    check("type_from_to_edge", *quad_model.type_from_to_edge);

    check("equal_from_to",      *quad_model.equal_from_to);
    check("equal_from_type",    *quad_model.equal_from_type);
    check("equal_to_type",      *quad_model.equal_to_type);
    check("equal_from_to_type", *quad_model.equal_from_to_type);

    check("equal_from_to_inverted",   *quad_model.equal_from_to_inverted);
    check("equal_from_type_inverted", *quad_model.equal_from_type_inverted);
    check("equal_to_type_inverted",   *quad_model.equal_to_type_inverted);
}
