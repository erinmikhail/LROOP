#include <iostream>
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

void printMenu() {
    std::cout << "\n=== Figure Management System ===\n";
    std::cout << "1. Add Square\n";
    std::cout << "2. Add Rectangle\n";
    std::cout << "3. Add Trapezoid\n";
    std::cout << "4. Remove Figure\n";
    std::cout << "5. Print All Figures\n";
    std::cout << "6. Calculate Total Area\n";
    std::cout << "7. Clear All Figures\n";
    std::cout << "8. Exit\n";
    std::cout << "Choose an option: ";
}

void addSquare(FigureArray& array) {
    std::cout << "Enter 4 points for Square (x1 y1 x2 y2 x3 y3 x4 y4): ";
    Square* square = new Square();
    try {
        std::cin >> *square;
        array.addFigure(square);
        std::cout << "Square added successfully!\n";
    } catch (const std::exception&) {
        delete square;
        std::cout << "Error reading square data!\n";
    }
}

void addRectangle(FigureArray& array) {
    std::cout << "Enter 4 points for Rectangle (x1 y1 x2 y2 x3 y3 x4 y4): ";
    Rectangle* rectangle = new Rectangle();
    try {
        std::cin >> *rectangle;
        array.addFigure(rectangle);
        std::cout << "Rectangle added successfully!\n";
    } catch (const std::exception&) {
        delete rectangle;
        std::cout << "Error reading rectangle data!\n";
    }
}

void addTrapezoid(FigureArray& array) {
    std::cout << "Enter 4 points for Trapezoid (x1 y1 x2 y2 x3 y3 x4 y4): ";
    Trapezoid* trapezoid = new Trapezoid();
    try {
        std::cin >> *trapezoid;
        array.addFigure(trapezoid);
        std::cout << "Trapezoid added successfully!\n";
    } catch (const std::exception&) {
        delete trapezoid;
        std::cout << "Error reading trapezoid data!\n";
    }
}

void removeFigure(FigureArray& array) {
    int index;
    std::cout << "Enter index to remove: ";
    std::cin >> index;
    array.removeFigure(index);
}

int main() {
    FigureArray figureArray;
    int choice;
    
    do {
        printMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addSquare(figureArray);
                break;
            case 2:
                addRectangle(figureArray);
                break;
            case 3:
                addTrapezoid(figureArray);
                break;
            case 4:
                removeFigure(figureArray);
                break;
            case 5:
                figureArray.printAll();
                break;
            case 6:
                std::cout << "Total area: " << figureArray.totalArea() << std::endl;
                break;
            case 7:
                figureArray.clear();
                std::cout << "All figures cleared!\n";
                break;
            case 8:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);
    
    return 0;
}