#include "TestDate.h"
#include "../../../Time/Date.h"
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

void testDate(){
    testDateSimple();
}