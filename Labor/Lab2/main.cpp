#include <iostream>
#include <cassert>
#include "Length.h"

void test_constructors() {
    // Test default constructor
    Length len1;
    assert(len1.getValue() == 0.0f);
    assert(len1.getMeasuringUnit() == Length::MeasuringUnit::Meter);

    // Test constructor with parameters
    Length len2(10.0f, Length::MeasuringUnit::Kilometer);
    assert(len2.getValue() == 10.0f);
    assert(len2.getMeasuringUnit() == Length::MeasuringUnit::Kilometer);

    // Test copy constructor
    Length len3(len2);
    assert(len3.getValue() == 10.0f);
    assert(len3.getMeasuringUnit() == Length::MeasuringUnit::Kilometer);
}

void testGetters() {
    Length length(10, Length::MeasuringUnit::Meter);
    assert(length.getValue() == 10);
    assert(length.getMeasuringUnit() == Length::MeasuringUnit::Meter);
}

void testText() {
    // Create a length object to test string representation
    Length length1(10, Length::MeasuringUnit::Meter);
    Length length2(10, Length::MeasuringUnit::Centimeter);
    Length length3(10, Length::MeasuringUnit::Kilometer);

    // Test string representation
    std::string str1 = length1.text();
    std::string str2 = length2.text();
    std::string str3 = length3.text();
    assert(str1 == "10.00 Meters");
    assert(str2 == "10.00 Centimeters");
    assert(str3 == "10.00 Kilometers");
}

void testOperatorFunctions() {
    // Create two length objects to test addition, subtraction and comparison
    Length length1(10, Length::MeasuringUnit::Meter);
    Length length2(5, Length::MeasuringUnit::Meter);

    // Test addition and comparison
    Length lengthSum = length1.add(length2);
    assert(lengthSum.getValue() == 15);
    assert(lengthSum.getMeasuringUnit() == Length::MeasuringUnit::Meter);
    assert(length1.compare(length2) == 1);
    assert(length2.compare(length1) == -1);
    assert(length1.compare(length1) == 0);

    // Test subtraction
    Length lengthDiff = length1.subtract(length2);
    assert(lengthDiff.getValue() == 5);
    assert(lengthDiff.getMeasuringUnit() == Length::MeasuringUnit::Meter);

    // Test scaling and division
    Length length3(4, Length::MeasuringUnit::Meter);
    length3.scale(2);
    assert(length3.getValue() == 8);
    length3.divide(4);
    assert(length3.getValue() == 2);

    // Test invalid division (dividing by 0)
    bool exceptionThrown = false;
    try {
        length3.divide(0);
    }
    catch (const std::exception &) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
}

void testOverloadedOperators() {
    // Create two length objects to test the overloaded operators
    Length length1(10, Length::MeasuringUnit::Meter);
    Length length2(5, Length::MeasuringUnit::Meter);

    // Test the overloaded == operator
    assert(length1 == length1);
    assert(!(length1 == length2));

    // Test the overloaded != operator
    assert(!(length1 != length1));
    assert(length1 != length2);

    // Test the overloaded < operator
    assert(!(length1 < length1));
    assert(!(length1 < length2));
    assert(length2 < length1);

    // Test the overloaded <= operator
    assert(length1 <= length1);
    assert(!(length1 <= length2));
    assert(length2 <= length1);

    // Test the overloaded > operator
    assert(!(length1 > length1));
    assert(length1 > length2);
    assert(!(length2 > length1));

    // Test the overloaded >= operator
    assert(length1 >= length1);
    assert(length1 >= length2);
    assert(!(length2 >= length1));

    // Test addition
    Length length3(10, Length::MeasuringUnit::Meter);
    Length length4(5, Length::MeasuringUnit::Meter);
    Length lengthSum = length1 + length2;
    assert(lengthSum.getValue() == 15);
    assert(lengthSum.getMeasuringUnit() == Length::MeasuringUnit::Meter);

    // Test subtraction
    Length lengthDiff = length1 - length2;
    assert(lengthDiff.getValue() == 5);
    assert(lengthDiff.getMeasuringUnit() == Length::MeasuringUnit::Meter);

    // Test multiplication
    length3 * 2;
    assert(length3.getValue() == 20);
    assert(length3.getMeasuringUnit() == Length::MeasuringUnit::Meter);

    // Test division
    length3 / 4;
    assert(length3.getValue() == 5);
    assert(length3.getMeasuringUnit() == Length::MeasuringUnit::Meter);

    // Test invalid division (dividing by 0)
    bool exceptionThrown = false;
    try {
        length1 / 0;
    }
    catch (const std::exception &) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
}

int main() {
    test_constructors();
    testGetters();
    testText();
    testOperatorFunctions();
    testOverloadedOperators();
    return 0;
}
