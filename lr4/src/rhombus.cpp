#include "Rhombus.h"
#include <iostream>

template<typename T>
Rhombus<T>::Rhombus(T d1, T d2) : diagonal1(d1), diagonal2(d2) {
    initializeVertices();
}

template<typename T>
void Rhombus<T>::initializeVertices() {
    this->vertices.clear();
    T half_d1 = diagonal1 / 2;
    T half_d2 = diagonal2 / 2;
    
    this->vertices.push_back(std::make_unique<Point<T>>(0, half_d2));
    this->vertices.push_back(std::make_unique<Point<T>>(half_d1, 0));
    this->vertices.push_back(std::make_unique<Point<T>>(0, -half_d2));
    this->vertices.push_back(std::make_unique<Point<T>>(-half_d1, 0));
}

template<typename T>
Point<T> Rhombus<T>::geometricCenter() const {
    return Point<T>(0, 0);
}

template<typename T>
double Rhombus<T>::area() const {
    return (diagonal1 * diagonal2) / 2.0;
}

template<typename T>
void Rhombus<T>::printVertices() const {
    for (const auto& vertex : this->vertices) {
        std::cout << *vertex << " ";
    }
    std::cout << "\n";
}

template<typename T>
std::string Rhombus<T>::getName() const {
    return "Rhombus";
}

template<typename T>
bool Rhombus<T>::operator==(const Figure<T>& other) const {
    const Rhombus* otherRhombus = dynamic_cast<const Rhombus*>(&other);
    if (!otherRhombus) return false;
    return diagonal1 == otherRhombus->diagonal1 && 
           diagonal2 == otherRhombus->diagonal2;
}

template class Rhombus<int>;
template class Rhombus<double>;
template class Rhombus<float>;