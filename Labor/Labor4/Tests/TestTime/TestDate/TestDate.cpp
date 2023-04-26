#include "TestDate.h"
#include "../../../Time/Date/Date.h"
#include <cassert>

void testDateSimple() {
    // Create a new Date object
    Time::Date d(2023, 4, 18);

    // Test the getters
    assert(d.getYear() == 2023);
    assert(d.getMonth() == 4);
    assert(d.getDay() == 18);

    // Test the setters
    d.setYear(2024);
    assert(d.getYear() == 2024);

    d.setMonth(5);
    assert(d.getMonth() == 5);

    d.setDay(6);
    assert(d.getDay() == 6);
}

void testDateExtended(){
    // Test constructors and getters
    Time::Date date1(2023, 4, 26);
    Time::Date date2(2024, 2, 29);
    Time::Date date3(2025, 12, 31);

    assert(date1.getYear() == 2023);
    assert(date1.getMonth() == 4);
    assert(date1.getDay() == 26);

    assert(date2.getYear() == 2024);
    assert(date2.getMonth() == 2);
    assert(date2.getDay() == 29);

    assert(date3.getYear() == 2025);
    assert(date3.getMonth() == 12);
    assert(date3.getDay() == 31);

    // Test setters and safeguards
    date1.setYear(2022);
    date1.setMonth(10);
    date1.setDay(31);

    assert(date1.getYear() == 2022);
    assert(date1.getMonth() == 10);
    assert(date1.getDay() == 31);

    bool caughtException = false;
    try {
        date1.setYear(-2022);
    } catch (std::invalid_argument &e) {
        caughtException = true;
    }
    assert(caughtException);

    caughtException = false;
    try {
        date1.setMonth(13);
    } catch (std::invalid_argument &e) {
        caughtException = true;
    }
    assert(caughtException);

    caughtException = false;
    try {
        date1.setDay(32);
    } catch (std::invalid_argument &e) {
        caughtException = true;
    }
    assert(caughtException);

    // Test copy constructor and assignment operator
    Time::Date date4 = date3;
    assert(date4.getYear() == 2025);
    assert(date4.getMonth() == 12);
    assert(date4.getDay() == 31);

    date4 = date2;
    assert(date4.getYear() == 2024);
    assert(date4.getMonth() == 2);
    assert(date4.getDay() == 29);

    // Test comparison operators
    assert(date1 < date2);
    assert(date2 > date1);
    assert(date1 <= date1);
    assert(date1 >= date1);
    assert(date1 != date2);
    assert(date2 == date4);
}

void testDate(){
    testDateSimple();
    testDateExtended();
}