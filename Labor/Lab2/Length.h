#pragma once

class Length {
public:
    enum MeasuringUnit {
        Kilometer,
        Meter,
        Centimeter,
    };

    enum ImperialMeasuringUnit {
        Mile,
        Yard,
        Inch,
    };

private:
    float value;
    MeasuringUnit measuringUnit;

public:
    //Constructor with 0 parameters
    Length();

    //Constructor with 2 parameters
    explicit Length(float _value, MeasuringUnit _measuringUnit = MeasuringUnit::Meter);

    //Copy constructor of the object
    Length(Length const &length);

    //Value getter
    [[nodiscard]] float getValue() const;

    //Measuring Unit getter
    MeasuringUnit getMeasuringUnit();

    //Add two Objects together
    Length add(const Length &other);

    //Subtract an object from another
    Length subtract(const Length &other);

    //Multiply a length with a scalar
    void scale(float number);

    //Divide a length by a scalar
    void divide(float number);

    //Return a string representation of the object
    std::string text();

    //Converts the current metric value in an imperial value
    float convertToImperial(ImperialMeasuringUnit imperialMeasuringUnit);

    //Returns the current length in meters
    float inMeters();

    //Compare two lengths together
    short compare(const Length &other);

    //Overloaded operators
    Length &operator=(const Length &other);
    Length operator+(const Length &other);
    Length operator-(const Length &other);
    void operator*(float number);
    void operator/(float number);
    bool operator==(const Length &other) const;
    bool operator<(const Length &other) const;
    bool operator<=(const Length &other) const;
    bool operator>(const Length &other) const;
    bool operator>=(const Length &other) const;
};