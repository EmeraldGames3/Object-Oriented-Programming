#pragma once
#include <string>


class Length {
private:
    float value;
    std::string measuringUnit;

public:
    //Constructor with 0 parameters
    Length();

    //Constructor with 1 parameter
    explicit Length(float _value);

    //Constructor with 2 parameters
    Length(float _value, const std::string &_measuringUnit);

    //Constructor for creating an exact copy of the object
    Length(Length const &length);

    [[nodiscard]] float getValue() const;

    std::string getMeasuringUnit();

    Length add(const Length &other);

    Length subtract(const Length &other);

    void scale(float number);

    void divide(float number);

    std::string text();

    short compare(const Length &other);

    //Overload the '=' operator
    Length &operator=(const Length &other) {
        if (this != &other) {
            this->value = other.value;
            this->measuringUnit = other.measuringUnit;
        }
        return *this;
    }

    //Overload the '==' operator
    bool operator==(const Length &other) const {
        if (this->value != other.value) return false;
        if (this->measuringUnit != other.measuringUnit) return false;
        return true;
    }

    //Overload the * Operator
    bool operator*(float number) { value *= number; }

    //Overload the / Operator
    bool operator/(float number) { value /= number; }

    //Overload the + Operator
    Length operator+(const Length &other){
        if (this->measuringUnit != other.measuringUnit) throw std::exception();
        return {this->value + other.value, this->measuringUnit};
    }

    //Overload the - Operator
    Length operator-(const Length &other){
        if (this->measuringUnit != other.measuringUnit) throw std::exception();
        return {this->value - other.value, this->measuringUnit};
    }
};