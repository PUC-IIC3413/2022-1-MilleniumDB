#include "object_file.h"

#include <cassert>
#include <cstring>

#include "base/exceptions.h"
#include "storage/file_manager.h"

using namespace std;

ObjectFile::ObjectFile(const string& filename) :
    file (file_manager.get_file(file_manager.get_file_id(filename)))
{
    file.seekg (0, file.end);
    auto end_pos = file.tellg();

    if (end_pos == 0) {
        // The object file doesn't exist
        capacity = INITIAL_SIZE;
        objects = new char[INITIAL_SIZE];
        objects[0] = '\0'; // skip the first byte to prevent the ID = 0
        current_end = 1;
    } else {
        // The object already exists
        capacity = end_pos;
        objects = new char[end_pos];
        file.seekg(0, file.beg);
        file.read(objects, end_pos);
        current_end = end_pos;
    }
}


ObjectFile::~ObjectFile() {
    file.seekg(0, file.beg);
    file.write(objects, current_end);
    delete[] objects;
}


std::string ObjectFile::get_string(uint64_t id) const {
    return std::string(&objects[id]);
}


uint64_t ObjectFile::write(const std::string& str) {
    assert(str.size() >= 8); // 7 or less bytes can be inlined

    uint64_t write_pos = current_end;
    // check the is enough space
    while (current_end + str.size() + 1 >= capacity) {
        // duplicate buffer
        char* new_objects = new char[capacity*2];
        std::memcpy(
            new_objects,
            objects,
            capacity);

        capacity *= 2;

        delete[] objects;
        objects = new_objects;
    }
    // write
    std::memcpy(
        &objects[current_end],
        str.data(),
        str.size());

    current_end += str.size();
    objects[current_end] = '\0';
    ++current_end;

    return write_pos;
}
