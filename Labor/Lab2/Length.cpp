#include <iomanip>
#include "Length.h"

Length::Length() : value(0), measuringUnit(MeasuringUnit::Meter) {}

Length::Length(float _value, MeasuringUnit _measuringUnit) : value(_value), measuringUnit(_measuringUnit) {}

Length::Length(const Length &length) {
    this->value = length.value;
    this->measuringUnit = length.measuringUnit;
}

float Length::getValue() const {
    return value;
}

Length::MeasuringUnit Length::getMeasuringUnit() {
    return measuringUnit;
}

Length Length::add(const Length &other) {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    return Length(this->value + other.value, this->measuringUnit);
}

Length Length::subtract(const Length &other) {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    return Length(this->value - other.value, this->measuringUnit);
}

void Length::scale(float number) {
    value *= number;
}

void Length::divide(float number) {
    if (number == 0)
        throw std::exception();
    value /= number;
}

std::string Length::text() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;

    switch (measuringUnit) {
        case MeasuringUnit::Meter:
            return stream.str() + " Meter";
        case MeasuringUnit::Centimeter:
            return stream.str() + " Centimeter";
        case MeasuringUnit::Kilometer:
            return stream.str() + " Kilometer";
    }
}

short Length::compare(const Length &other) {
    if (this->measuringUnit != other.measuringUnit)
        throw std::exception();
    else if (this->value == other.value)
        return 0;
    else if (this->value > other.value)
        return 1;
    else
        return -1;
}

float Length::convertToImperial(Length::ImperialMeasuringUnit imperialMeasuringUnit) {
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

bool Length::operator==(const Length &other) const {
    if (this->value != other.value)
        return false;
    if (this->measuringUnit != other.measuringUnit)
        return false;
    return true;
}

void Length::operator*(float number) {
    value *= number;
}

void Length::operator/(float number) {
    value /= number;
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