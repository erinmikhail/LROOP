#pragma once
#include "Figure.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

template<typename T>
class Hexagon : public Figure<T> {
private:
    T radius;
    
public:
    Hexagon(T r);
    void initializeVertices();
    
    Point<T> geometricCenter() const override;
    double area() const override;
    void printVertices() const override;
    std::string getName() const override;
    bool operator==(const Figure<T>& other) const override;
};