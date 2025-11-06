#pragma once
#include <type_traits>
#include <memory>
#include <iostream>

template<typename T>
class Point {
private:
    T x, y;
    
    static_assert(std::is_scalar_v<T>, "T must be a scalar type");
    
public:
    Point(T x = 0, T y = 0);
    
    T getX() const;
    T getY() const;
    
    void setX(T x);
    void setY(T y);

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    bool operator==(const Point& other) const;
    Point operator+(const Point& other) const;
    Point operator/(T divisor) const;
};