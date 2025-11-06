#pragma once
#include <memory>
#include <stdexcept>
#include <utility>
#include <iostream>
#include "Figure.h"

template<typename T>
class Array {
private:
    std::unique_ptr<T[]> data;
    size_t capacity;
    size_t size;
    
    void resize(size_t newCapacity);
    
public:
    Array();
    Array(size_t initialCapacity);
    
    void push_back(const T& value);
    void push_back(T&& value);
    void remove(size_t index);
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    size_t getSize() const;
    size_t getCapacity() const;
    double totalArea() const;
    void printAll() const;
};