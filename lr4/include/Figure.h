#pragma once
#include "Point.h"
#include <memory>
#include <vector>
#include <iostream>
#include <string>

template<typename T>
class Figure {
protected:
    std::vector<std::unique_ptr<Point<T>>> vertices;
    
public:
    virtual ~Figure() = default;
    
    virtual Point<T> geometricCenter() const = 0;
    virtual double area() const = 0;
    virtual void printVertices() const = 0;
    virtual std::string getName() const = 0;
    
    virtual bool operator==(const Figure& other) const = 0;

    virtual operator double() const {
        return area();
    }

    void printInfo() const {
        std::cout << getName() << ":\n";
        std::cout << "  Vertices: ";
        printVertices();
        std::cout << "  Geometric center: " << geometricCenter() << "\n";
        std::cout << "  Area: " << area() << "\n";
    }
};