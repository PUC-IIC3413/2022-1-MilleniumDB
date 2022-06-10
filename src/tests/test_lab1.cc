#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <stdio.h>

#include "storage/buffer_manager.h"
#include "storage/file_manager.h"
#include "storage/index/object_file/heap_file.h"

using namespace std;

int main(int argc, char **argv) {

    if(argc!=3) {
        std::cout << "No hay la cantidad de argumentos correctos\n";
        return 0;
    }


    string db_folder = "tests/dbs/test_heapfile";
    namespace fs = std::experimental::filesystem;
    if (fs::exists(db_folder) && !fs::is_empty(db_folder)) {
        remove( "tests/dbs/test_heapfile/heapfile.dat" );
    }
    if (fs::exists(argv[2])) {
        remove( argv[2] );
    }
    // Normalmente iniciar el QuadModel inicia a FileManager y BufferManager
    // como ahora no estamos usando a QuadModel es necesario inicializar explicitamente
    FileManager::init(db_folder);
    BufferManager::init(BufferManager::DEFAULT_SHARED_BUFFER_POOL_SIZE, 0, 0);

    HeapFile heap_file("heapfile.dat");

    ifstream testfile(argv[1]); // in file
    ofstream outfile(argv[2]); // out file
    string line;
    if (testfile.is_open() & outfile.is_open()) {
        while ( getline (testfile,line) ){
            stringstream ss(line);
            string order;
            ss >> order;
            string info;
            ss >> info;
            if (order == "w") {
                auto id = heap_file.write(info);
                outfile << id << "\n";
            } else if (order == "r") {
                auto id = stoi(info);
                auto str = heap_file.get_string(id);
                outfile << str << "\n";
            } else if(order == "d") {
                auto id = stoi(info);
                heap_file.remove(id);
                outfile << "remove\n";
            }
        }
        testfile.close();
    }


    // Usualmente nunca hay que llamar a los destructores de forma explícita, pero la forma en que están diseñados
    // buffer_manager y file_manager así lo requieren (Normalmente la destruccion de QuadModel se encarga de eso)
    buffer_manager.~BufferManager();
    file_manager.~FileManager();

    return 1;
}
