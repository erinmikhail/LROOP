#include "Hexagon.h"
#include <iostream>

template<typename T>
Hexagon<T>::Hexagon(T r) : radius(r) {
    initializeVertices();
}

template<typename T>
void Hexagon<T>::initializeVertices() {
    this->vertices.clear();
    for (int i = 0; i < 6; ++i) {
        double angle = 2 * M_PI * i / 6;
        T x = static_cast<T>(radius * std::cos(angle));
        T y = static_cast<T>(radius * std::sin(angle));
        this->vertices.push_back(std::make_unique<Point<T>>(x, y));
    }
}

template<typename T>
Point<T> Hexagon<T>::geometricCenter() const {
    return Point<T>(0, 0);
}

template<typename T>
double Hexagon<T>::area() const {
    return (3 * std::sqrt(3) / 2) * radius * radius;
}

template<typename T>
void Hexagon<T>::printVertices() const {
    for (const auto& vertex : this->vertices) {
        std::cout << *vertex << " ";
    }
    std::cout << "\n";
}

template<typename T>
std::string Hexagon<T>::getName() const {
    return "Hexagon";
}

template<typename T>
bool Hexagon<T>::operator==(const Figure<T>& other) const {
    const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
    if (!otherHexagon) return false;
    return radius == otherHexagon->radius;
}

template class Hexagon<int>;
template class Hexagon<double>;
template class Hexagon<float>;