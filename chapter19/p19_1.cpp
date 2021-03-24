#include <cstdlib>
#include <iostream>

void *operator new(size_t size) {
    if (void *mem = malloc(size)) {
        return mem;
    } else {
        throw std::bad_alloc();
    }
}

void operator delete(void* ptr) noexcept{
    free(ptr);
}


