#include "Six.h"

size_t Six::myMax(size_t a, size_t b) const {
    return (a > b) ? a : b;
}

bool Six::isValidDigit(unsigned char digit) const {
    return digit <= 5;
}

unsigned char Six::charToDigit(char c) const {
    if (c >= '0' && c <= '5') {
        return c - '0';
    }
    throw "Invalid digit for six-based number";
}

char Six::digitToChar(unsigned char digit) const {
    return '0' + digit;
}

void Six::removeLeadingZeros() {
    while (_size > 1 && _data[_size - 1] == 0) {
        _size--;
    }
}

void Six::ensureCapacity(size_t requiredCapacity) {
    if (requiredCapacity <= _capacity) {
        return;
    }
    
    size_t newCapacity = requiredCapacity * 2;
    unsigned char* newData = new unsigned char[newCapacity];
    
    for (size_t i = 0; i < _size; ++i) {
        newData[i] = _data[i];
    }
    
    for (size_t i = _size; i < newCapacity; ++i) {
        newData[i] = 0;
    }
    
    delete[] _data;
    _data = newData;
    _capacity = newCapacity;
}

int Six::compare(const Six& other) const {
    if (_size != other._size) {
        return _size > other._size ? 1 : -1;
    }
    
    for (size_t i = _size; i > 0; --i) {
        size_t idx = i - 1;
        if (_data[idx] != other._data[idx]) {
            return _data[idx] > other._data[idx] ? 1 : -1;
        }
    }
    return 0;
}

Six::Six() : _size(1), _capacity(1), _data(new unsigned char[1]) {
    _data[0] = 0;
}

Six::Six(const size_t n, unsigned char t) : _size(n), _capacity(n) {
    if (n == 0) {
        throw "Size cannot be zero";
    }
    if (!isValidDigit(t)) {
        throw "Invalid digit";
    }
    
    _data = new unsigned char[_capacity];
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = t;
    }
    removeLeadingZeros();
}

Six::Six(const initializer_list<unsigned char> &t) 
    : _size(t.size()), _capacity(t.size()) {
    
    if (t.size() == 0) {
        throw "Initializer list cannot be empty";
    }
    
    _data = new unsigned char[_capacity];
    
    size_t index = 0;
    for (auto it = t.begin(); it != t.end(); ++it) {
        if (!isValidDigit(*it)) {
            delete[] _data;
            throw "Invalid digit in initializer list";
        }
        _data[index++] = *it;
    }
    
    for (size_t i = 0; i < _size / 2; ++i) {
        unsigned char temp = _data[i];
        _data[i] = _data[_size - 1 - i];
        _data[_size - 1 - i] = temp;
    }
    
    removeLeadingZeros();
}

Six::Six(const string &t) : _size(t.length()), _capacity(t.length()) {
    if (t.empty()) {
        throw "String cannot be empty";
    }
    
    _data = new unsigned char[_capacity];
    
    for (size_t i = 0; i < _size; ++i) {
        unsigned char digit = charToDigit(t[_size - 1 - i]);
        _data[i] = digit;
    }
    removeLeadingZeros();
}

Six::Six(const Six& other) : _size(other._size), _capacity(other._size) {
    _data = new unsigned char[_capacity];
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

Six::Six(Six&& other) noexcept 
    : _size(other._size), _capacity(other._capacity), _data(other._data) {
    
    other._data = nullptr;
    other._size = 0;
    other._capacity = 0;
}

Six::~Six() noexcept {
    if (_data != nullptr) {
        delete[] _data;
    }
}

size_t Six::getSize() const {
    return _size;
}

ostream& Six::print(ostream& outputStream) const {
    for (size_t i = _size; i > 0; --i) {
        outputStream << digitToChar(_data[i - 1]);
    }
    return outputStream;
}

Six Six::add(const Six& other) const {
    Six result = *this;
    return result.addAssign(other);
}

Six Six::subtract(const Six& other) const {
    if (this->less(other)) {
        throw "Cannot subtract larger number";
    }
    
    Six result = *this;
    return result.subtractAssign(other);
}

Six Six::copy() const {
    return Six(*this);
}

bool Six::equals(const Six& other) const {
    return compare(other) == 0;
}

bool Six::greater(const Six& other) const {
    return compare(other) > 0;
}

bool Six::less(const Six& other) const {
    return compare(other) < 0;
}

Six& Six::addAssign(const Six& other) {
    size_t maxSize = myMax(_size, other._size);
    ensureCapacity(maxSize + 1);
    
    unsigned char carry = 0;
    size_t i = 0;
    
    for (; i < maxSize || carry; ++i) {
        unsigned char sum = carry;
        if (i < _size) sum += _data[i];
        if (i < other._size) sum += other._data[i];
        
        carry = sum / 6;
        if (i >= _size) {
            if (i >= _capacity) {
                ensureCapacity(i + 1);
            }
            _size = i + 1;
        }
        _data[i] = sum % 6;
    }
    
    if (i > _size) {
        _size = i;
    }
    
    removeLeadingZeros();
    return *this;
}

Six& Six::subtractAssign(const Six& other) {
    if (this->less(other)) {
        throw "Cannot subtract larger number";
    }
    
    unsigned char borrow = 0;
    for (size_t i = 0; i < _size; ++i) {
        int diff = _data[i] - borrow;
        if (i < other._size) {
            diff -= other._data[i];
        }
        
        if (diff < 0) {
            diff += 6;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        _data[i] = diff;
    }
    
    removeLeadingZeros();
    return *this;
}