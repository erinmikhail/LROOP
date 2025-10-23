#include <iostream>
#include "conversion12to24.h"  

using namespace std;

int main() {
    string inputTime;

    // получаем входные данные
    cout << "Введите входные данные по примеру (8:30 am или 8:30 pm): ";
    getline(cin, inputTime);

    int hour, minute;
    string period;

    if (!parseTimeString(inputTime, hour, minute, period)) {
        cerr << "Ошибка, неправильно ввели данные, посмотрите пример" << endl;
        return 1;
    }

    cout << "Результат преобразования сейчас появится (потерпи): " << endl;

    // Вызов функций и вывод полученных значений
    string result = convert12To24(hour, minute, period);  // ← исправил название функции

    cout << "В 12-часовом формате: " << inputTime << endl;
    cout << "В 24-часовом формате: " << result << endl;

    return 0; // конецццц ура.......
}