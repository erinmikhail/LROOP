#include <iostream>
#include <memory>
#include <cmath>
#include <limits>
#include "include/Point.h"
#include "include/Figure.h"
#include "include/Rhombus.h"
#include "include/Pentagon.h"
#include "include/Hexagon.h"
#include "include/Array.h"

using namespace std;

using namespace std;


void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void demonstrateBaseTypeArray() {
    cout << "=== Demonstrating Array with base type Figure<int> ===" << endl;
    
    Array<shared_ptr<Figure<int>>> figures;
    
    figures.push_back(make_shared<Rhombus<int>>(4, 6));
    figures.push_back(make_shared<Pentagon<int>>(5));
    figures.push_back(make_shared<Hexagon<int>>(4));
    
    cout << "Total figures: " << figures.getSize() << endl;
    figures.printAll();
    cout << "Total area: " << figures.totalArea() << endl;

    cout << "\nRemoving figure at index 1..." << endl;
    figures.remove(1);
    figures.printAll();
    cout << "Total area after removal: " << figures.totalArea() << endl;
}

void interactiveMode() {
    cout << "\n=== Interactive Mode ===" << endl;
    Array<shared_ptr<Figure<double>>> figures;
    
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Rhombus\n";
        cout << "2. Add Pentagon\n";
        cout << "3. Add Hexagon\n";
        cout << "4. Remove figure by index\n";
        cout << "5. Print all figures\n";
        cout << "6. Calculate total area\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        
        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        switch (choice) {
            case 1: {
                double d1, d2;
                cout << "Enter diagonals for rhombus: ";
                if (cin >> d1 >> d2) {
                    figures.push_back(make_shared<Rhombus<double>>(d1, d2));
                    cout << "Rhombus added.\n";
                } else {
                    clearInput();
                    cout << "Invalid input.\n";
                }
                break;
            }
            case 2: {
                double radius;
                cout << "Enter radius for pentagon: ";
                if (cin >> radius) {
                    figures.push_back(make_shared<Pentagon<double>>(radius));
                    cout << "Pentagon added.\n";
                } else {
                    clearInput();
                    cout << "Invalid input.\n";
                }
                break;
            }
            case 3: {
                double radius;
                cout << "Enter radius for hexagon: ";
                if (cin >> radius) {
                    figures.push_back(make_shared<Hexagon<double>>(radius));
                    cout << "Hexagon added.\n";
                } else {
                    clearInput();
                    cout << "Invalid input.\n";
                }
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter index to remove: ";
                if (cin >> index) {
                    if (index < figures.getSize()) {
                        figures.remove(index);
                        cout << "Figure removed.\n";
                    } else {
                        cout << "Invalid index.\n";
                    }
                } else {
                    clearInput();
                    cout << "Invalid input.\n";
                }
                break;
            }
            case 5:
                figures.printAll();
                break;
            case 6:
                cout << "Total area: " << figures.totalArea() << endl;
                break;
            case 0:
                cout << "Exiting interactive mode.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

int main() {
    try {
        demonstrateBaseTypeArray();
        interactiveMode();
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}