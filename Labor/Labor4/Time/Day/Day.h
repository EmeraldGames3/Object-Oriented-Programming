#pragma once

#include <stdexcept>
#include <string>

namespace Time {
    ///@deprecated
    class Day {
    private:
        short hour;
        short minute;
        short second;

    public:
        //Default constructor with default parameters
        explicit Day(short _hour = 0, short _minute = 0, short _second = 0);

        //Copy constructor
        Day(const Day &other) = default;

        //Destructor
        ~Day() = default;

        ///Get the date as a string
        [[nodiscard]] std::string toString() const;

        ///Getters
        [[nodiscard]] short getHour() const;
        [[nodiscard]] short getMinute() const;
        [[nodiscard]] short getSecond() const;

        ///Setters
        void setHour(short newHour);
        void setMinute(short newMinute);
        void setSecond(short newSecond);

        ///Increment by a given value
        void incrementHour(short hours);
        void incrementMinute(short minutes);
        void incrementSecond(short seconds);

        ///Decrement by a given value
        void decrementHour(short hours);
        void decrementMinute(short minutes);
        void decrementSecond(short seconds);

        ///Multiply with a scalar
        void multiply(short scalar);

        ///Divide with a scalar
        void divide(short scalar);

        ///Overloaded assignment operator
        Day &operator=(const Day &other);

        ///Overloaded comparison operators
        bool operator==(const Day &other) const;
        bool operator!=(const Day &other) const;
        bool operator<(const Day &other) const;
        bool operator>(const Day &other) const;
        bool operator<=(const Day &other) const;
        bool operator>=(const Day &other) const;

        ///Overloaded arithmetic operators
        Day operator+(const Day &other) const;
        Day operator-(const Day &other) const;
        Day operator*(short scalar) const;
        Day operator/(short scalar) const;

        ///Overloaded compound assignment operators
        Day &operator+=(const Day &other);
        Day &operator-=(const Day &other);
        Day &operator*=(short scalar);
        Day &operator/=(short scalar);
    };
}