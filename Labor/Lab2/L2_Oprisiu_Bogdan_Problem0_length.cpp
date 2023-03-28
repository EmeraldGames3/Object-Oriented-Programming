#include <exception>
#include <iomanip>
#include "L2_Oprisiu_Bogdan_Problem0_length.h"

/** @brief Default constructor of length **/
Length::Length() : value(0), measuringUnit(MeasuringUnit::Meter) {}

/**
 * @brief Constructor with one default parameter
 * @details The default measuring unit is meters, if it is not specified
**/
Length::Length(float _value, MeasuringUnit _measuringUnit) : value(_value), measuringUnit(_measuringUnit) {}

/** @brief Copy constructor for the class Length **/
Length::Length(const Length &length) {
    this->value = length.value;
    this->measuringUnit = length.measuringUnit;
}

/** @brief getter **/
float Length::getValue() const {
    return value;
}

/** @brief Measuring Unit getter **/
Length::MeasuringUnit Length::getMeasuringUnit() {
    return measuringUnit;
}

/**
 * @brief Add two objects of type Length
 * @return A new object of type length
 * @details The object has the length equal to the sum of the lengths of the other objects
 * @throws exception If the measuring units of the objects do not match
**/
Length Length::add(const Length &other) {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    return Length(this->value + other.value, this->measuringUnit);
}

/**
 * @brief Add two objects of type Length
 * @return A new object of type length
 * @details The object has the length equal to the difference of the two lengths of the other objects
 * @throws exception If the measuring units of the objects do not match
**/
Length Length::subtract(const Length &other) {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    return Length(this->value - other.value, this->measuringUnit);
}

/** @brief Multiply the value of a length by a scalar **/
void Length::scale(float number) {
    value *= number;
}

/**
 * @brief Multiply the value of a length by a scalar
 * @throws exception For zero division
**/
void Length::divide(float number) {
    if (number == 0)
        throw std::exception();
    value /= number;
}

/**
 * @brief Compares two Lengths
 * @return 0 If they are equal
 * @return 1 If this length is greater then the other length
 * @return -1 If this length is less than the other length
**/
short Length::compare(const Length &other) {
    const float epsilon = 0.0001f;
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    else if ((std::abs(this->value - other.value) < epsilon) && (this->measuringUnit == other.measuringUnit))
        return 0;
    else if (this->value > other.value)
        return 1;
    else
        return -1;
}

/**
 * @brief Converts the object to a string
 * @details We use a precision of 2 digits for the representation of the value
 * @return A string representation of the object
 */
std::string Length::text() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;

    switch (measuringUnit) {
        case MeasuringUnit::Meter:
            return stream.str() + " Meters";
        case MeasuringUnit::Centimeter:
            return stream.str() + " Centimeters";
        case MeasuringUnit::Kilometer:
            return stream.str() + " Kilometers";
    }
}

/** @brief Converts the metric value of the Length object to an imperial value **/
float Length::convertToImperial(
        Length::ImperialMeasuringUnit imperialMeasuringUnit) {
    //Constants used for conversion
    const float meterToMiles = 0.00062137;
    const float meterToYards = 1.0936133;
    const float meterToInch = 39.3700787;

    float lengthInMeters = inMeters();

    switch (imperialMeasuringUnit) {
        case ImperialMeasuringUnit::Mile:
            return lengthInMeters * meterToMiles;
        case Yard:
            return lengthInMeters * meterToYards;
        case Inch:
            return lengthInMeters * meterToInch;
    }
}

float Length::inMeters() {
    switch (measuringUnit) {
        case MeasuringUnit::Meter:
            return value;
        case MeasuringUnit::Centimeter:
            return value / 100;
        case MeasuringUnit::Kilometer:
            return value * 1000;
    }
}

Length &Length::operator=(const Length &other) {
    if (this != &other) {
        this->value = other.value;
        this->measuringUnit = other.measuringUnit;
    }
    return *this;
}

Length Length::operator+(const Length &other) {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    return Length(this->value + other.value, this->measuringUnit);
}

Length Length::operator-(const Length &other) {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    return Length(this->value - other.value, this->measuringUnit);
}

void Length::operator*(float number) {
    value *= number;
}

void Length::operator/(float number) {
    if (number == 0)
        throw std::exception();
    value /= number;
}

bool Length::operator==(const Length &other) const {
    const float epsilon = 0.0001f;
    return (std::abs(this->value - other.value) < epsilon) && (this->measuringUnit == other.measuringUnit);
}


bool Length::operator<(const Length &other) const {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    return (this->getValue() < other.getValue());
}

bool Length::operator<=(const Length &other) const {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    return (this->getValue() <= other.getValue());
}

bool Length::operator>(const Length &other) const {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    return (this->getValue() > other.getValue());
}

bool Length::operator>=(const Length &other) const {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    return (this->getValue() >= other.getValue());
}
