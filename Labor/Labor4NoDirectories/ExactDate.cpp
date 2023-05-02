#include "ExactDate.h"

Time::ExactDate::ExactDate(int _year, int _month, Day _day) : year(_year), month(_month), day(_day){}

int Time::ExactDate::getYear() const {
    return year;
}

int Time::ExactDate::getMonth() const {
    return month;
}

Time::Day Time::ExactDate::getDay() const {
    return day;
}

void Time::ExactDate::setYear(int newYear) {
    year = newYear;
}

void Time::ExactDate::setMonth(int newMonth) {
    month = newMonth;
}

void Time::ExactDate::setDay(Day newDay) {
    day = newDay;
}
