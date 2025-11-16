#pragma once
#include "Figure.h"
#include <cmath>

template<typename T>
class Rhombus : public Figure<T> {
private:
    T diagonal1, diagonal2;
    
public:
    Rhombus(T d1, T d2);
    void initializeVertices();
    
    Point<T> geometricCenter() const override;
    double area() const override;
    void printVertices() const override;
    std::string getName() const override;
    bool operator==(const Figure<T>& other) const override;
};