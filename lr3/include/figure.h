#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <exception>

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0);
    bool operator==(const Point& other) const;
};

class Figure {
public:
    virtual ~Figure() = default;
    virtual Point center() const = 0;
    virtual operator double() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual Figure* copy() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
};

class FigureArray {
private:
    std::vector<Figure*> figures;
public:
    ~FigureArray();
    void addFigure(Figure* fig);
    void removeFigure(int index);
    size_t size() const;
    Figure* getFigure(int index) const;
    void printAll() const;
    double totalArea() const;
    void clear();
};

#endif