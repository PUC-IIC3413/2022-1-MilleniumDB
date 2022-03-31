#ifndef STORAGE__HEAP_FILE_H_
#define STORAGE__HEAP_FILE_H_

#include "storage/file_manager.h"
#include "storage/page.h"

#include <fstream>
#include <memory>
#include <string>
#include <vector>

class HeapFile
{
    public:
        HeapFile(const std::string& filename);
        ~HeapFile() = default;

        uint64_t write(const std::string& bytes);
        std::string get_string(uint64_t id) const;
        void remove(uint64_t id);
        
        void flush();
    private:
        FileId fileid;
};

#endif
