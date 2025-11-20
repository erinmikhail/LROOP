#pragma once
#include <memory_resource>
#include <iterator>
#include <type_traits>

using namespace std;

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;

        template<typename... Args>
        Node(Node* nxt, Args&&... args) 
            : data(forward<Args>(args)...), next(nxt) {}
    };

    Node* top_node;
    pmr::polymorphic_allocator<Node> allocator;
    size_t stack_size;

public:
    class Iterator {
    private:
        Node* current;
    public:
        using iterator_category = forward_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit Iterator(Node* node = nullptr) : current(node) {}
        Iterator& operator++() { if (current) current = current->next; return *this; }
        Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; }
        reference operator*() const { return current->data; }
        pointer operator->() const { return &current->data; }
        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return !(*this == other); }
    };

    explicit Stack(pmr::memory_resource* alloc = pmr::get_default_resource())
        : top_node(nullptr), allocator(alloc), stack_size(0) {}

    ~Stack() { clear(); }

    // УДАЛИТЕ ПЕРЕМЕЩАЮЩИЕ ОПЕРАТОРЫ ВРЕМЕННО
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    Stack(Stack&&) = delete;
    Stack& operator=(Stack&&) = delete;

    template<typename U = T>
    void push(U&& value) {
        Node* new_node = allocator.allocate(1);
        try {
            allocator.construct(new_node, top_node, forward<U>(value));
            top_node = new_node;
            ++stack_size;
        } catch (...) {
            allocator.deallocate(new_node, 1);
            throw;
        }
    }

    void pop() {
        if (!empty()) {
            Node* old_top = top_node;
            top_node = top_node->next;
            allocator.destroy(old_top);
            allocator.deallocate(old_top, 1);
            --stack_size;
        }
    }

    T& top() {
        if (empty()) throw runtime_error("Stack is empty");
        return top_node->data;
    }

    const T& top() const {
        if (empty()) throw runtime_error("Stack is empty");
        return top_node->data;
    }

    bool empty() const { return top_node == nullptr; }
    size_t size() const { return stack_size; }

    void clear() {
        while (!empty()) pop();
    }

    Iterator begin() { return Iterator(top_node); }
    Iterator end() { return Iterator(nullptr); }
    Iterator begin() const { return Iterator(top_node); }
    Iterator end() const { return Iterator(nullptr); }
};