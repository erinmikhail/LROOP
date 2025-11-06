#include "Pentagon.h"
#include <iostream>

template<typename T>
Pentagon<T>::Pentagon(T r) : radius(r) {
    initializeVertices();
}

template<typename T>
void Pentagon<T>::initializeVertices() {
    this->vertices.clear();
    for (int i = 0; i < 5; ++i) {
        double angle = 2 * M_PI * i / 5;
        T x = static_cast<T>(radius * std::cos(angle));
        T y = static_cast<T>(radius * std::sin(angle));
        this->vertices.push_back(std::make_unique<Point<T>>(x, y));
    }
}

template<typename T>
Point<T> Pentagon<T>::geometricCenter() const {
    return Point<T>(0, 0);
}

template<typename T>
double Pentagon<T>::area() const {
    return (5.0 / 2.0) * radius * radius * std::sin(2 * M_PI / 5);
}

template<typename T>
void Pentagon<T>::printVertices() const {
    for (const auto& vertex : this->vertices) {
        std::cout << *vertex << " ";
    }
    std::cout << "\n";
}

template<typename T>
std::string Pentagon<T>::getName() const {
    return "Pentagon";
}

template<typename T>
bool Pentagon<T>::operator==(const Figure<T>& other) const {
    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    if (!otherPentagon) return false;
    return radius == otherPentagon->radius;
}

template class Pentagon<int>;
template class Pentagon<double>;
template class Pentagon<float>;