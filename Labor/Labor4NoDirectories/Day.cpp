#include "Day.h"

///Default constructor
Time::Day::Day(short _hour, short _minute, short _second) : hour{_hour}, minute{_minute}, second{_second} {}

///Get the date as a string
std::string Time::Day::toString() const {
    return std::to_string(hour) + '/' + std::to_string(minute) + '/' + std::to_string(second);
}

///Hour getter
short Time::Day::getHour() const {
    return hour;
}

///Minute getter
short Time::Day::getMinute() const {
    return minute;
}

///Second getter
short Time::Day::getSecond() const {
    return second;
}

/**
 * @brief Hour setter
 * @throws invalid_argument
 */
void Time::Day::setHour(short newHour) {
    if (newHour >= 24) throw std::invalid_argument("There are only 24 hours in a day");
    if (newHour < 0) throw std::invalid_argument("Time is positive");
    hour = newHour;
}

/**
 * @brief Minute setter
 * @throws invalid_argument
 */
void Time::Day::setMinute(short newMinute) {
    if (newMinute >= 60) throw std::invalid_argument("There are only 60 minutes in an hour");
    if (newMinute < 0) throw std::invalid_argument("Time is positive");
    minute = newMinute;
}

/**
 * @brief Second setter
 * @throws invalid_argument
 */
void Time::Day::setSecond(short newSecond) {
    if (newSecond >= 60) throw std::invalid_argument("There are only 60 seconds in a minute");
    if (newSecond < 0) throw std::invalid_argument("Time is positive");
    second = newSecond;
}

///Increment Hour by a given value
void Time::Day::incrementHour(short hours) {
    if (hours < 0) throw std::invalid_argument("Hour value cannot be negative");
    hour = static_cast<short>(hour + hours); //Avoid narrowing conversion type warning
    hour %= 24;
}

///Decrement Hour by a given value
void Time::Day::decrementHour(short hours) {
    if (hours < 0) throw std::invalid_argument("Hour value cannot be negative");
    hour = static_cast<short>(hour - hours); //Avoid narrowing conversion type warning
    while (hour < 0) {
        hour += 24;
    }
    hour %= 24;
}

///Increment Minute by a given value
void Time::Day::incrementMinute(short minutes) {
    if (minutes < 0) throw std::invalid_argument("Minutes cannot be negative");
    minute = static_cast<short>(minute + minutes); //Avoid narrowing conversion type warning
    incrementHour(static_cast<short>(minute / 60)); //Avoid narrowing conversion type warning
    minute %= 60;
}

///Decrement Minute by a given value
void Time::Day::decrementMinute(short minutes) {
    if (minutes < 0) throw std::invalid_argument("Minutes cannot be negative");
    minute = static_cast<short>(minute - minutes); //Avoid narrowing conversion type warning
    while (minute < 0) {
        minute += 60;
        decrementHour(1);
    }
}

///Increment Second by a given value
void Time::Day::incrementSecond(short seconds) {
    if (seconds < 0) throw std::invalid_argument("Seconds cannot be negative");
    second = static_cast<short>(second + seconds); //Avoid narrowing conversion type warning
    incrementMinute(static_cast<short>(second / 60));
    second %= 60;
}

///Decrement Second by a given value
void Time::Day::decrementSecond(short seconds) {
    if (seconds < 0) throw std::invalid_argument("Seconds cannot be negative");
    second = static_cast<short>(second - seconds); //Avoid narrowing conversion type warning
    while (second < 0) {
        second += 60;
        decrementMinute(1);
    }
}

///Multiply with a scalar
void Time::Day::multiply(short scalar) {
    if (scalar < 0) throw std::invalid_argument("Time is positive");
    if(scalar == 0) throw std::invalid_argument("Multiplication with 0 is not allowed");
    hour = static_cast<short>(hour * scalar);//Avoid narrowing conversion type warning
    minute = static_cast<short>(minute * scalar);
    second = static_cast<short>(second * scalar);
    // Handle carry-over from seconds to minutes to hours
    while (second >= 60) {
        minute = static_cast<short>(minute + second / 60);
        second %= 60;
    }
    while (minute >= 60) {
        hour = static_cast<short>(hour + minute / 60);
        minute %= 60;
    }
    hour %= 24;
}

///Divide with a scalar
void Time::Day::divide(short scalar) {
    if (scalar < 0) throw std::invalid_argument("Time is positive");
    if(scalar == 0) throw std::invalid_argument("Division by 0 is not allowed");
    hour = static_cast<short>(hour / scalar);//Avoid narrowing conversion type warning
    minute = static_cast<short>(minute / scalar);
    second = static_cast<short>(second / scalar);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///Overloaded = operator
Time::Day &Time::Day::operator=(const Day &other) {
    if (this != &other) { // check for self-assignment
        hour = other.hour;
        minute = other.minute;
        second = other.second;
    }
    return *this;
}

/// == operator
bool Time::Day::operator==(const Day &other) const {
    return hour == other.hour && minute == other.minute && second == other.second;
}

///Overloaded != operator
bool Time::Day::operator!=(const Day &other) const {
    return !(*this == other);
}

///Overloaded < operator
bool Time::Day::operator<(const Day &other) const {
    return (hour < other.hour) ||
           (hour == other.hour && minute < other.minute) ||
           (hour == other.hour && minute == other.minute && second < other.second);
}

///Overloaded > operator
bool Time::Day::operator>(const Day &other) const {
    return other < *this;
}

///Overloaded <= operator
bool Time::Day::operator<=(const Day &other) const {
    return !(other < *this);
}

///Overloaded >= operator
bool Time::Day::operator>=(const Day &other) const {
    return !(*this < other);
}

///Overloaded + operator
Time::Day Time::Day::operator+(const Time::Day &other) const {
    Day result;

    result.setHour(hour);
    result.setMinute(minute);
    result.setSecond(second);

    result.incrementHour(other.hour);
    result.incrementMinute(other.minute);
    result.incrementSecond(other.second);

    return result;
}

///Overloaded - operator
Time::Day Time::Day::operator-(const Time::Day &other) const {
    Day result;

    result.setHour(hour);
    result.setMinute(minute);
    result.setSecond(second);

    result.decrementHour(other.hour);
    result.decrementMinute(other.minute);
    result.decrementSecond(other.second);

    return result;
}

///Overloaded * operator
Time::Day Time::Day::operator*(short scalar) const {
    Day result;

    result.setHour(hour);
    result.setMinute(minute);
    result.setSecond(second);

    result.multiply(scalar);
    return result;
}

///Overloaded / operator
Time::Day Time::Day::operator/(short scalar) const {
    Day result;

    result.setHour(hour);
    result.setMinute(minute);
    result.setSecond(second);

    result.divide(scalar);
    return result;
}

///Overloaded += operator
Time::Day &Time::Day::operator+=(const Time::Day &other) {
    incrementHour(other.hour);
    incrementMinute(other.minute);
    incrementSecond(other.second);
    return *this;
}

///Overloaded -= operator
Time::Day &Time::Day::operator-=(const Time::Day &other) {
    decrementHour(other.hour);
    decrementMinute(other.minute);
    decrementSecond(other.second);
    return *this;
}

///Overloaded *= operator
Time::Day &Time::Day::operator*=(short scalar) {
    multiply(scalar);
    return *this;
}

///Overloaded /= operator
Time::Day &Time::Day::operator/=(short scalar) {
    divide(scalar);
    return *this;
}