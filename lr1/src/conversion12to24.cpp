#include "conversion12to24.h"
#include <string>


using namespace std;

string convert12To24(int hour, int minute, const string& period) {
    int hour24;
    
    // Правильное преобразование
    if (period == "am") {
        hour24 = hour; // 12 am -> 12, 1-11 am -> без изменений
    } else {
        if (hour == 12) {
            hour24 = 0; // 12 pm -> 00
        } else {
            hour24 = hour + 12; // 1-11 pm -> +12 часов
        }
    }
    
    // ТОЛЬКО для часа добавляем ведущий ноль (если нужно)
    string hourStr;
    if (hour24 < 10) {
        hourStr = "0" + to_string(hour24);
    } else {
        hourStr = to_string(hour24);
    }
    
    // Для минут НЕ добавляем ведущий ноль - они уже двузначные!
    string minuteStr = to_string(minute);
    
    return hourStr + minuteStr;
}

bool isValid12HourTime(int hour, int minute, const string& period) {
    if (hour < 1 || hour > 12) return false;
    if (minute < 0 || minute > 59) return false;
    if (period != "am" && period != "pm") return false;
    return true;
}

bool parseTimeString(const string& timeStr, int& hour, int& minute, string& period) {
    size_t colonPos = timeStr.find(':');
    if (colonPos == string::npos) return false;
    
    size_t spacePos = timeStr.find(' ', colonPos + 1);
    if (spacePos == string::npos) return false;
    
    // Извлечение часа
    string hourStr = timeStr.substr(0, colonPos);
    hour = stoi(hourStr);
    
    // Извлечение минут (уже будут двузначными)
    string minuteStr = timeStr.substr(colonPos + 1, spacePos - colonPos - 1);
    minute = stoi(minuteStr);
    
    // Извлечение периода
    period = timeStr.substr(spacePos + 1);
    
    return isValid12HourTime(hour, minute, period);
}