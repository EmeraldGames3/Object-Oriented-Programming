#include "Date.h"

Time::Date::Date(int _year, int _month, int _day) : year(_year), month(_month), day(_day){}

int Time::Date::getYear() const {
    return year;
}

int Time::Date::getMonth() const {
    return month;
}

int Time::Date::getDay() const {
    return day;
}

void Time::Date::setYear(int newYear) {
    year = newYear;
}

void Time::Date::setMonth(int newMonth) {
    month = newMonth;
}

void Time::Date::setDay(int newDay) {
    day = newDay;
}