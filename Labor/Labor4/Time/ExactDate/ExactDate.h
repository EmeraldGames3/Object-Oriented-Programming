#pragma once

#include "../Day/Day.h"

namespace Time {
    class ExactDate {
    private:
        int year;
        int month;
        Day day;

    public:
        //Default Constructor
        explicit ExactDate(int _year = 0, int _month = 0, Day _day = Day());

        //Copy constructor
        ExactDate(const ExactDate &other) = default;

        //Destructor
        ~ExactDate() = default;

        ///Getters
        [[nodiscard]] int getYear() const;

        [[nodiscard]] int getMonth() const;

        [[nodiscard]] Day getDay() const;

        ///Setters
        void setYear(int newYear);

        void setMonth(int newMonth);

        void setDay(Day newDay);
    };
}