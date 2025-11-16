#include "Point.h"
#include <iostream>

template<typename T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template<typename T>
T Point<T>::getX() const { return x; }

template<typename T>
T Point<T>::getY() const { return y; }

template<typename T>
void Point<T>::setX(T x) { this->x = x; }

template<typename T>
void Point<T>::setY(T y) { this->y = y; }

template<typename T>
bool Point<T>::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

template<typename T>
Point<T> Point<T>::operator+(const Point& other) const {
    return Point<T>(x + other.x, y + other.y);
}

template<typename T>
Point<T> Point<T>::operator/(T divisor) const {
    return Point<T>(x / divisor, y / divisor);
}

template class Point<int>;
template class Point<double>;
template class Point<float>;