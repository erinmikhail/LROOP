#pragma once

#include <iostream>
#include <string>

using namespace std;

class Six {
public:
    Six();
    Six(const size_t n, unsigned char t = 0);
    Six(const initializer_list<unsigned char> &t);
    Six(const string &t);
    Six(const Six& other);
    Six(Six&& other) noexcept;
    virtual ~Six() noexcept;

    Six add(const Six& other) const;
    Six subtract(const Six& other) const;
    Six copy() const;
    
    bool equals(const Six& other) const;
    bool greater(const Six& other) const;
    bool less(const Six& other) const;
    
    Six& addAssign(const Six& other);
    Six& subtractAssign(const Six& other);

    ostream& print(ostream& outputStream) const;
    size_t getSize() const;

private:
    size_t _size;
    size_t _capacity;
    unsigned char* _data;

    bool isValidDigit(unsigned char digit) const;
    unsigned char charToDigit(char c) const;
    char digitToChar(unsigned char digit) const;
    void removeLeadingZeros();
    void ensureCapacity(size_t requiredCapacity);
    int compare(const Six& other) const;
    size_t myMax(size_t a, size_t b) const;
};