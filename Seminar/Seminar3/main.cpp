#include <iostream>
#include <cmath>

using std::cout, std::string;

enum Week {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

string to_string(Week day) {
    switch (day) {
        case Week::Monday:
            return "Monday";
        case Week::Tuesday:
            return "Tuesday";
        case Week::Wednesday:
            return "Wednesday";
        case Week::Thursday:
            return "Thursday";
        case Week::Friday:
            return "Friday";
        case Week::Saturday:
            return "Saturday";
        case Week::Sunday:
            return "Sunday";
        default:
            return "";
    }
}

Week lookUp(int number) {
    switch (number) {
        case Monday:
            return Monday;
        case Tuesday:
            return Tuesday;
        case Wednesday:
            return Wednesday;
        case Thursday:
            return Thursday;
        case Friday:
            return Friday;
        case Saturday:
            return Saturday;
        case Sunday:
            return Sunday;
        default:
            throw std::exception();
    }
}

Week lookUp(const string &weekName) {
    if (weekName == "Monday") {
        return Monday;
    } else if (weekName == "Tuesday") {
        return Tuesday;
    } else if (weekName == "Wednesday") {
        return Wednesday;
    } else if (weekName == "Thursday") {
        return Thursday;
    } else if (weekName == "Friday") {
        return Friday;
    } else if (weekName == "Saturday") {
        return Saturday;
    } else if (weekName == "Sunday") {
        return Sunday;
    }
    throw std::exception();
}

class GeometricForm {
public:
    virtual double calculateArea() {return 0;};
    virtual void printDescription() {};
};

struct Point {
    double x;
    double y;
    explicit Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

template<typename Type>
class Circle : public GeometricForm {
private:
    Point center;
    Type radius;
public:
    explicit Circle(Point _center = Point(0, 0), Type _radius = 1) : center(_center) {
        if (radius < 0) {
            throw std::invalid_argument("Radius must be positive");
        }
        radius = _radius;
    }

    [[nodiscard]] double calculateArea() const {
        return std::numbers::pi * radius * radius;
    }

    void printDescription() override {
        cout << "Circle with center: " << center.x << ' ' << center.y << "and radius: " << radius << '\n';
    }
};

template<typename Type>
class Square : public GeometricForm {
private:
    Type sideLength;
    Point leftUpPoint;

public:
    explicit Square(Point _leftUpPoint = Point(0, 0), Type _sideLength = 1) : sideLength(_sideLength) {
        if (sideLength < 0) {
            throw std::invalid_argument("Radius must be positive");
        }
        sideLength = _sideLength;
    }

    [[nodiscard]] double calculateArea() const {
        return sideLength * sideLength;
    }

    void printDescription() override {
        cout << "The left corner of the square is on " << leftUpPoint.x << " " << leftUpPoint.y
             << ". The square has the side Length of " << sideLength << '\n';
    }
};

int main() {
    Point O(0,0);
    Circle<int> circle(Point);
    Square<float> square(Point);
}