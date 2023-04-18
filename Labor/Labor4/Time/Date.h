#pragma once

#include <stdexcept>

namespace Time {
    class Date {
        //TODO add additional functionalities and safeguards
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

        ///Getters
        [[nodiscard]] int getYear() const;
        [[nodiscard]] int getMonth() const;
        [[nodiscard]] int getDay() const;

        ///Setters
        void setYear(int newYear);
        void setMonth(int newMonth);
        void setDay(int newDay);
    };
}