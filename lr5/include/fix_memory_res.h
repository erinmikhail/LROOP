#pragma once
#include <memory_resource>
#include <list>
#include <cstddef>
 
using namespace std;

class FixedMemoryResource : public pmr::memory_resource {
    private:
        void* memory_block;
        size_t total_size;
        size_t used_size;
        bool is_allocated;
    
    protected:
        void* do_allocate(size_t bytes, size_t alignment) override;
        void do_deallocate(void* ptr, size_t bytes, size_t alignment)override;
        bool do_is_equal(const pmr::memory_resource& other) const noexcept override;

    public:
        explicit FixedMemoryResource(size_t size);
        ~FixedMemoryResource()override;
        FixedMemoryResource(const FixedMemoryResource&) = delete;
        FixedMemoryResource& operator=(const FixedMemoryResource&) = delete;

        size_t get_total_size() const { return total_size; }
        size_t get_used_size() const { return used_size; }

        size_t get_available_size() const { return total_size - used_size; }

        void reset();
};