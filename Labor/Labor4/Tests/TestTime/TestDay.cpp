#include "TestDay.h"
#include <iostream>

using Time::Day;

void testConstructors() {
    // Test default constructor
    Time::Day day1;
    assert(day1.getHour() == 0);
    assert(day1.getMinute() == 0);
    assert(day1.getSecond() == 0);

    // Test parameterized constructor
    Day day2(10, 30, 45);
    assert(day2.getHour() == 10);
    assert(day2.getMinute() == 30);
    assert(day2.getSecond() == 45);

    // Test copy constructor
    Day day3(day2);
    assert(day3.getHour() == 10);
    assert(day3.getMinute() == 30);
    assert(day3.getSecond() == 45);
}

void testAssignmentOperators() {
    // Test assignment operator
    Day day1(8, 15, 20);
    Day day2 = day1;
    assert(day2.getHour() == 8);
    assert(day2.getMinute() == 15);
    assert(day2.getSecond() == 20);

    // Test self-assignment
    day2 = day2;
    assert(day2.getHour() == 8);
    assert(day2.getMinute() == 15);
    assert(day2.getSecond() == 20);

    // Test chaining
    Day day3(12, 45, 30);
    Day day4(14, 20, 50);
    Day day5(16, 10, 15);
    day1 = day2 = day3 = day4 = day5;
    assert(day1.getHour() == 16);
    assert(day1.getMinute() == 10);
    assert(day1.getSecond() == 15);
    assert(day2.getHour() == 16);
    assert(day2.getMinute() == 10);
    assert(day2.getSecond() == 15);
    assert(day3.getHour() == 16);
    assert(day3.getMinute() == 10);
    assert(day3.getSecond() == 15);
    assert(day4.getHour() == 16);
    assert(day4.getMinute() == 10);
    assert(day4.getSecond() == 15);
    assert(day5.getHour() == 16);
    assert(day5.getMinute() == 10);
    assert(day5.getSecond() == 15);
}

void testGettersAndSetters() {
    // Test setters
    Day day;
    day.setHour(5);
    day.setMinute(10);
    day.setSecond(15);
    assert(day.getHour() == 5);
    assert(day.getMinute() == 10);
    assert(day.getSecond() == 15);

    // Test setters with invalid input
    try {
        day.setHour(-5);
    } catch (std::invalid_argument& e) {
        assert(std::string(e.what()) == "Time is positive");
    }
    try {
        day.setMinute(70);
    } catch (std::invalid_argument& e) {
        assert(std::string(e.what()) == "There are only 60 minutes in an hour");
    }
    try {
        day.setSecond(80);
    } catch (std::invalid_argument& e) {
        assert(std::string(e.what()) == "There are only 60 seconds in a minute");
    }

    // Test getters
    assert(day.getHour() == 5);
    assert(day.getMinute() == 10);
    assert(day.getSecond() == 15);
}

void testComparisonOperators() {
    // Test equality operator
    Day day1(5, 10, 15);
    Day day2(5, 10, 15);
    Day day3(6, 20, 30);
    assert(day1 == day2);
    assert(!(day1 == day3));

    // Test inequality operator
    assert(day1 != day3);
    assert(!(day1 != day2));

    // Test less than operator
    assert(day1 < day3);
    assert(!(day1 < day2));
    assert(!(day3 < day1));

    // Test greater than operator
    assert(day3 > day1);
    assert(!(day2 > day1));
    assert(!(day1 > day3));

    // Test less than or equal to operator
    assert(day1 <= day2);
    assert(day1 <= day3);
    assert(!(day3 <= day1));

    // Test greater than or equal to operator
    assert(day1 >= day2);
    assert(day3 >= day1);
    assert(!(day1 >= day3));
}

void testHourManipulation() {
    Time::Day day(23, 59, 59);

    // Test incrementHour
    day.incrementHour(1);
    assert(day.getHour() == 0 && day.getMinute() == 59 && day.getSecond() == 59);

    day.incrementHour(23);
    assert(day.getHour() == 23 && day.getMinute() == 59 && day.getSecond() == 59);

    day.incrementHour(0);
    assert(day.getHour() == 23 && day.getMinute() == 59 && day.getSecond() == 59);

    try {
        day.incrementHour(-1);
        assert(false);
    } catch(const std::invalid_argument& ia) {
        assert(std::string(ia.what()) == "Hour value cannot be negative");
    }

    day.incrementHour(24); // test with 24 hours
    assert(day.getHour() == 23 && day.getMinute() == 59 && day.getSecond() == 59);

    day.incrementHour(100); // test with 100 hours
    assert(day.getHour() == 3 && day.getMinute() == 59 && day.getSecond() == 59);

    day.setHour(23); //This line exists because my calculations were off

    // Test decrementHour
    day.decrementHour(1);
    assert(day.getHour() == 22 && day.getMinute() == 59 && day.getSecond() == 59);

    day.decrementHour(22);
    assert(day.getHour() == 0 && day.getMinute() == 59 && day.getSecond() == 59);

    day.decrementHour(0);
    assert(day.getHour() == 0 && day.getMinute() == 59 && day.getSecond() == 59);

    day.decrementHour(1);
    assert(day.getHour() == 23 && day.getMinute() == 59 && day.getSecond() == 59);

    try {
        day.decrementHour(-1);
        assert(false);
    } catch(const std::invalid_argument& ia) {
        assert(std::string(ia.what()) == "Hour value cannot be negative");
    }

    day.decrementHour(24); // test with 24 hours
    assert(day.getHour() == 23 && day.getMinute() == 59 && day.getSecond() == 59);

    day.decrementHour(100); // test with 100 hours
    assert(day.getHour() == 19 && day.getMinute() == 59 && day.getSecond() == 59);
}

void testMinuteManipulation() {
    Time::Day day(23, 59, 59);

    // Test incrementMinute
    try {
        day.incrementMinute(-1);
        assert(false); // if we reach here, the test has failed
    } catch(const std::invalid_argument& ia) {
        assert(std::string(ia.what()) == "Minutes cannot be negative");
    }

    day.incrementMinute(1);
    assert(day.getHour() == 0 && day.getMinute() == 0 && day.getSecond() == 59);

    day.incrementMinute(60);
    assert(day.getHour() == 1 && day.getMinute() == 0 && day.getSecond() == 59);

    day.incrementMinute(0);
    assert(day.getHour() == 1 && day.getMinute() == 0 && day.getSecond() == 59);

    // Test decrementMinute
    try {
        day.decrementMinute(-1);
        assert(false); // if we reach here, the test has failed
    } catch(const std::invalid_argument& ia) {
        assert(std::string(ia.what()) == "Minutes cannot be negative");
    }

    //This lines exist because my calculations were off
    day.setHour(23);
    day.setMinute(59);

    day.decrementMinute(1);
    assert(day.getHour() == 23 && day.getMinute() == 58 && day.getSecond() == 59);

    day.decrementMinute(60);
    assert(day.getHour() == 22 && day.getMinute() == 58 && day.getSecond() == 59);

    day.decrementMinute(0);
    assert(day.getHour() == 22 && day.getMinute() == 58 && day.getSecond() == 59);
}

void testSecondManipulation() {
    Time::Day day(0, 0, 0);

    // Test incrementSecond
    day.incrementSecond(1);
    assert(day.getHour() == 0 && day.getMinute() == 0 && day.getSecond() == 1);

    day.incrementSecond(59);
    assert(day.getHour() == 0 && day.getMinute() == 1 && day.getSecond() == 0);

    try {
        day.incrementSecond(-1);
        assert(false);
    } catch(const std::invalid_argument& ia) {
        assert(std::string(ia.what()) == "Seconds cannot be negative");
    }

    // Test decrementSecond
    day.decrementSecond(1);
    assert(day.getHour() == 0 && day.getMinute() == 0 && day.getSecond() == 59);

    day.decrementSecond(60);
    assert(day.getHour() == 23 && day.getMinute() == 59 && day.getSecond() == 59);

    try {
        day.decrementSecond(-1);
        assert(false);
    } catch(const std::invalid_argument& ia) {
        assert(std::string(ia.what()) == "Seconds cannot be negative");
    }
}

void testDayParametersManipulation(){
    testHourManipulation();
    testMinuteManipulation();
    testSecondManipulation();
}

void testDay(){
    testConstructors();
    testAssignmentOperators();
    testGettersAndSetters();
    testComparisonOperators();
    testDayParametersManipulation();
}