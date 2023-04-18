#pragma once

#include <stdexcept>

namespace Time {
    class Date {
    private:
        int year;
        int month;
        int day;

    public:
        //Default Constructor
        explicit Date(int _year = 0, int _month = 0, int _day = 0);

        //Copy constructor
        Date(const Date &other) = default;

        //Destructor
        ~Date() = default;
    };
}