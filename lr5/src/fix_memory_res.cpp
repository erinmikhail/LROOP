#include "fix_memory_res.h"
#include <iostream>
#include <stdexcept>

using namespace std;

FixedMemoryResource::FixedMemoryResource(size_t size) 
    : total_size(size), used_size(0), is_allocated(false) {
    memory_block = ::operator new(size);
    if (!memory_block) {
        throw bad_alloc();
    }
    cout << "FixedMemoryResource created with " << size << " bytes\n";
}

FixedMemoryResource::~FixedMemoryResource() {
    ::operator delete(memory_block);
    cout << "FixedMemoryResource destroyed. Used " << used_size << "/" << total_size << " bytes\n";
}

void* FixedMemoryResource::do_allocate(size_t bytes, size_t alignment) {
    if (alignment > alignof(max_align_t)) {
        throw bad_alloc();
    }

    if (used_size + bytes > total_size) {
        throw bad_alloc();
    }

    void* ptr = static_cast<char*>(memory_block) + used_size;
    used_size += bytes;
    is_allocated = true;
    
    cout << "Allocated " << bytes << " bytes at " << ptr 
              << ". Total used: " << used_size << "/" << total_size << "\n";
    
    return ptr;
}

void FixedMemoryResource::do_deallocate(void* ptr, size_t bytes, size_t alignment) {
    cout << "Deallocated " << bytes << " bytes at " << ptr 
              << ". Memory will be available after reset()\n";
}

bool FixedMemoryResource::do_is_equal(const pmr::memory_resource& other) const noexcept {
    return this == &other;
}

void FixedMemoryResource::reset() {
    used_size = 0;
    is_allocated = false;
    cout << "Memory resource reset. Available: " << total_size << " bytes\n";
}