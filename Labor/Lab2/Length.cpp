#include <iomanip>
#include "Length.h"

Length::Length() {
    value = 0;
    measuringUnit = "Meter";
}

Length::Length(float _value) {
    value = _value;
    measuringUnit = "Meter";
}

Length::Length(float _value, const std::string &_measuringUnit) {
    value = _value;
    measuringUnit = _measuringUnit;
}

Length::Length(const Length &length) {
    value = length.value;
    measuringUnit = length.measuringUnit;
}

float Length::getValue() const { return value; }

std::string Length::getMeasuringUnit() { return measuringUnit; }

Length Length::add(const Length &other) {
    if (this->measuringUnit != other.measuringUnit) throw std::exception();
    return {this->value + other.value, this->measuringUnit};
}

Length Length::subtract(const Length &other) {
    if (this->measuringUnit != other.measuringUnit) throw std::exception();
    return {this->value - other.value, this->measuringUnit};
}

void Length::scale(float number) { value *= number; }

void Length::divide(float number) {
    if (number == 0) throw std::exception();
    value /= number;
}

std::string Length::text() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    return stream.str() + " " + measuringUnit;
}

short Length::compare(const Length &other) {
    if (this->measuringUnit != other.measuringUnit) throw std::exception();
    if (this->value == other.value) return 0;
    if (this->value > other.value) return 1;
    if (this->value < other.value) return -1;
}