#include "Array.h"
#include <iostream>

template<typename T>
void Array<T>::resize(size_t newCapacity) {
    std::unique_ptr<T[]> newData(new T[newCapacity]);
    
    for (size_t i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    
    data = std::move(newData);
    capacity = newCapacity;
}

template<typename T>
Array<T>::Array() : data(new T[10]), capacity(10), size(0) {}

template<typename T>
Array<T>::Array(size_t initialCapacity) : data(new T[initialCapacity]), 
                               capacity(initialCapacity), size(0) {}

template<typename T>
void Array<T>::push_back(const T& value) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size++] = value;
}

template<typename T>
void Array<T>::push_back(T&& value) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size++] = std::move(value);
}

template<typename T>
void Array<T>::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = std::move(data[i + 1]);
    }
    --size;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
size_t Array<T>::getSize() const { return size; }

template<typename T>
size_t Array<T>::getCapacity() const { return capacity; }

template<typename T>
double Array<T>::totalArea() const {
    double total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += static_cast<double>(*data[i]); 
    }
    return total;
}

template<typename T>
void Array<T>::printAll() const {
    if (size == 0) {
        std::cout << "Array is empty\n";
        return;
    }
    for (size_t i = 0; i < size; ++i) {
        std::cout << "Figure " << i << ": ";
        data[i]->printInfo(); 
    }
}

template class Array<std::shared_ptr<Figure<int>>>;
template class Array<std::shared_ptr<Figure<double>>>;
template class Array<std::shared_ptr<Figure<float>>>;