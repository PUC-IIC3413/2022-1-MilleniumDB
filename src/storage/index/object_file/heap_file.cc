#include "heap_file.h"

#include <iostream>
#include <cassert>
#include <cstring>

#include "storage/file_manager.h"
#include "storage/buffer_manager.h"

using namespace std;

HeapFile::HeapFile(const string& filename)
    : fileid(file_manager.get_file_id(filename))
{
}


std::string HeapFile::get_string(uint64_t id) const {
    // Vemos la página
    uint64_t page_number = id/65536;
    unsigned short  direction = id%65536;

    if(page_number > file_manager.count_pages(fileid))
    {
        return NULL;
    };
}


uint64_t HeapFile::write(const std::string& bytes) {
}

void HeapFile::flush()
{
    buffer_manager.flush();
}

void HeapFile::remove(uint64_t id)
{
}