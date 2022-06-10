#include "heap_file.h"

#include <iostream>
#include <string>

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
    // Obtenemos la pagina que se nos solicita
    Page& page = buffer_manager.get_page(fileid, page_number);
    char * page_bytes = page.get_bytes();
    // Revisamos si el dirsize es mayor a la direccion solicitada
    unsigned short dirsize;
    memcpy(&dirsize, &page_bytes[6], sizeof(unsigned short));
    if(dirsize < direction + 1)
    {
        return NULL;
    };
    // Vamos a buscar el pointer y largo
    unsigned short pointer;
    memcpy(&pointer, &page_bytes[10 + direction*4], sizeof(unsigned short));
    unsigned short length;
    memcpy(&length, &page_bytes[10 + direction*4 + 2], sizeof(unsigned short));
    // Copiamos la palabra en el vector
    std::string lectura(&page_bytes[pointer], &page_bytes[pointer] + length);
    
    // Marcamos que no necesitamos más la pagina
    buffer_manager.unpin(page);

    return lectura;
}


uint64_t HeapFile::write(const std::string& bytes) {
    // Ver largo
    unsigned short length = bytes.length();
    if(length > 4084)
    {
        return 0;
    }
    // Variables que utilizaremos
    uint_fast32_t count_pages = file_manager.count_pages(fileid);
    uint_fast32_t i = 0;
    Page* page;
    char* page_bytes;
    unsigned short freesize;
    unsigned short dirsize;
    // Buscar en alguna página si es que cabe
    bool found = false;
    while((i < count_pages) && !found)
    {
        page = &buffer_manager.get_page(fileid, i);
        page_bytes = page->get_bytes();
        memcpy(&freesize, &page_bytes[8], sizeof(unsigned short));
        if(freesize >= length + 4)
        {
            found = true;
        };
        i++;
    };

    // Si es que el archivo no tenia paginas o ninguna tenia
    // espacio suficiente
    if(!found)
    {
        page = &buffer_manager.append_page(fileid);
        page_bytes = page->get_bytes();
        freesize = 4086;
        uint_fast32_t page_number = page->get_page_number();
        char number[6];
        for(i = 0; i < 6; i++)
        {
            number[5 - i] = static_cast<char>(page_number);
            page_number = page_number/256;
        }
        memcpy(page_bytes, number, 6*sizeof(char));
    };
    // Vemos dirsize para buscar el pointer
    memcpy(&dirsize, &page_bytes[6], sizeof(unsigned short));
    // Buscamos el lugar para escribir
    unsigned short pointer;
    if(dirsize)
    {
        memcpy(&pointer, &page_bytes[10 + (dirsize-1)*4], sizeof(unsigned short));
    } else {
        pointer = 4096;
    }

    // Escribimos el puntero y largo
    pointer = pointer - length;
    memcpy(&page_bytes[10 + dirsize*4], &pointer, sizeof(unsigned short));
    memcpy(&page_bytes[10 + dirsize*4 + 2], &length, sizeof(unsigned short));

    // actualizamos el dirsize
    dirsize++;
    memcpy(&page_bytes[6], &dirsize, sizeof(unsigned short));

    // Actualizamos el freesize
    freesize -= (4 + length);
    memcpy(&page_bytes[8], &freesize, sizeof(unsigned short));

    // Escribimos la palabra
    memcpy(&page_bytes[pointer], &bytes[0], length);

    //indicamos la pagina como sucia y le hacemos unpin
    page->make_dirty();
    buffer_manager.unpin(*page);

    // Identificador = pointer*(2^16) + dirsize
    uint64_t identificador = page->get_page_number() * 65536 + dirsize - 1;
    return identificador;
}

void HeapFile::flush()
{
    buffer_manager.flush();
}

void HeapFile::remove(uint64_t id)
{
    // Vemos la página
    uint64_t page_number = id/65536;
    unsigned short  direction = id%65536;

    if(page_number > file_manager.count_pages(fileid))
    {
        return;
    };
    // Obtenemos la pagina que se nos solicita
    Page& page = buffer_manager.get_page(fileid, page_number);
    char * page_bytes = page.get_bytes();
    // Revisamos si el dirsize es mayor a la direccion solicitada
    unsigned short dirsize;
    memcpy(&dirsize, &page_bytes[6], sizeof(unsigned short));
    if(dirsize < direction + 1)
    {
        return;
    };
    // Vamos a buscar el pointer y largo
    unsigned short pointer;
    memcpy(&pointer, &page_bytes[10 + direction*4], sizeof(unsigned short));
    unsigned short length;
    memcpy(&length, &page_bytes[10 + direction*4 + 2], sizeof(unsigned short));
    // Si debemos mover palabras -> moverlas todas juntas
    if(dirsize > direction + 1)
    {
        // Copiamos todo lo que hay que mover:
        // Leemos el ultimo puntero y desde ahi copiamos todas las palabras que están
        // después a la que queremos eliminar
        unsigned short last_pointer;
        memcpy(&last_pointer, &page_bytes[10 + (dirsize - 1) * 4], sizeof(unsigned short));
        // Vemos cual es el largo total que debemos mover (todas las palabras)
        unsigned short total_length = pointer - last_pointer;
        char *words = new char[total_length];
        memcpy(words, &page_bytes[last_pointer], total_length);
        // Leemos todos los directorios que hay que cambiar su pointer
        // Cambiamos los pointers de cada uno
        // new_pointer = old_pointer + length;
        for(unsigned short i = 10 + (direction + 1)*4; i < 10 + (dirsize * 4); i = i + 4)
        {
            unsigned short old_pointer;
            memcpy(&old_pointer, &page_bytes[i], sizeof(unsigned short));
            if(old_pointer > 0)
            {
                unsigned short new_pointer = old_pointer + length;
                memcpy(&page_bytes[i], &new_pointer, sizeof(unsigned short));
            }
        }
        // marcamos con 0 la palabra que borramos
        // debe ser a lo más a la izquierda (porque movimos todos los string)
        for(unsigned short i = last_pointer; i < last_pointer + length; i++)
            page_bytes[i] = 0;
        // copiamos todas las palabras de vuelta
        memcpy(&page_bytes[last_pointer + length], words, total_length);
        delete[] words;
    } else { // Si justo es la ultima palabra (mas simple)
        for(unsigned short i = pointer; i < pointer + length; i++)
            page_bytes[i] = 0;
    }
    // Marcamos con 0 donde estaba la dirección
    for(unsigned short i = 10 + direction*4; i < 10 + direction*4 + 4; i++)
        page_bytes[i] = 0;
    //cambiamos freesize
    unsigned short freesize;
    memcpy(&freesize, &page_bytes[8], sizeof(unsigned short));
    freesize = freesize + length;
    memcpy(&page_bytes[8], &freesize, sizeof(unsigned short));
    page.make_dirty();
    // buffer_manager.unpin(page);
}