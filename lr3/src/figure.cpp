#include "figure.h"
#include <iostream>


Point::Point(double x, double y) : x(x), y(y) {}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}


FigureArray::~FigureArray() {
    clear();
}

void FigureArray::addFigure(Figure* fig) {
    figures.push_back(fig);
}

void FigureArray::removeFigure(int index) {
    if (index >= 0 && static_cast<size_t>(index) < figures.size()) {
        delete figures[index];
        figures.erase(figures.begin() + index);
        std::cout << "Figure removed successfully!\n";
    } else {
        std::cout << "Invalid index!\n";
    }
}

size_t FigureArray::size() const {
    return figures.size();
}

Figure* FigureArray::getFigure(int index) const {
    if (index >= 0 && static_cast<size_t>(index) < figures.size()) {
        return figures[index];
    }
    return nullptr;
}

void FigureArray::printAll() const {
    if (figures.empty()) {
        std::cout << "No figures in array.\n";
        return;
    }
    
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i << ":\n";
        std::cout << "  " << *figures[i] << std::endl;
        Point center = figures[i]->center();
        std::cout << "  Center: (" << center.x << ", " << center.y << ")\n";
        std::cout << "  Area: " << static_cast<double>(*figures[i]) << std::endl;
        std::cout << std::endl;
    }
}

double FigureArray::totalArea() const {
    double total = 0;
    for (const auto& fig : figures) {
        total += static_cast<double>(*fig);
    }
    return total;
}

void FigureArray::clear() {
    for (auto fig : figures) {
        delete fig;
    }
    figures.clear();
}