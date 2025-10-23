#include <iostream>
#include "Six.h"

using namespace std;

int main() {
    cout << "=== Лабораторная работа: Класс Six для шестиричных чисел ===" << endl;
    
    cout << "\n--- Создание объектов ---" << endl;
    
    Six num1("12345");
    cout << "Первое число: ";
    num1.print(cout) << endl;

    Six num2({1, 2, 3});
    cout << "Второе число: ";
    num2.print(cout) << endl;

    Six num3(4, 5);
    cout << "Третье число: ";
    num3.print(cout) << endl;

    cout << "\n--- Арифметические операции ---" << endl;
    
    Six sum = num1.add(num2);
    cout << "Сложение: ";
    num1.print(cout) << " + ";
    num2.print(cout) << " = ";
    sum.print(cout) << endl;

    Six diff = num1.subtract(num2);
    cout << "Вычитание: ";
    num1.print(cout) << " - ";
    num2.print(cout) << " = ";
    diff.print(cout) << endl;

    cout << "\n--- Операции сравнения ---" << endl;
    
    cout << "num1 equals num2: " << num1.equals(num2) << endl;
    cout << "num1 greater than num2: " << num1.greater(num2) << endl;
    cout << "num1 less than num2: " << num1.less(num2) << endl;

    cout << "\n--- Обработка исключений ---" << endl;

    try {
        Six error = num2.subtract(num1);
        cout << "Результат вычитания: ";
        error.print(cout) << endl;
    } catch (const char* e) {
        cerr << "Перехвачено исключение: " << e << endl;
    }

    cout << "\n--- Выход из main() ---" << endl;
    
    return 0;
}