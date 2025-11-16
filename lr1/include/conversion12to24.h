#ifndef CONVERSION12TO24_H
#define CONVERSION12TO24_H

#include <string>

// Объявляю функции ТАК ЖЕ как в .cpp файле
std::string convert12To24(int hour, int minute, const std::string& period);
bool parseTimeString(const std::string& timeStr, int& hour, int& minute, std::string& period);
bool isValid12HourTime(int hour, int minute, const std::string& period);

#endif