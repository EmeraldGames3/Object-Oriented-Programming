#include "TestExactDate.h"

void testExactDateSimple() {
    // Create a new ExactDate object
    Time::ExactDate ed(2023, 4, Time::Day(0, 0, 0));

    // Test the getters
    assert(ed.getYear() == 2023);
    assert(ed.getMonth() == 4);
    assert(ed.getDay() == Time::Day(0, 0, 0));

    // Test the setters
    ed.setYear(2024);
    assert(ed.getYear() == 2024);

    ed.setMonth(5);
    assert(ed.getMonth() == 5);

    ed.setDay(Time::Day(1, 1, 1));
    assert(ed.getDay() == Time::Day(1, 1, 1));
}

void testExactDate() {
    testExactDateSimple();
}