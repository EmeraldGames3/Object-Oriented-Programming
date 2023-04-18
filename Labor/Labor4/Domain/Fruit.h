#pragma once

#include <string>

using std::string;

class Fruit {
private:
    string name;
    string origin;
    int price;

public:
    ///Default Constructor
    Fruit();

    ///Copy constructor
    Fruit(const Fruit &other);

    ///Destructor
    ~Fruit() = default;

    ///Name getter
    string getName();

    ///Origin getter
    string getOrigin();

    ///Price getter
    [[nodiscard]] int getPrice() const;

    ///Price setter
    void setPrice(int newPrice);

    ///Overloaded operators
    Fruit &operator=(const Fruit &other);

    bool operator==(const Fruit &other) const;

    bool operator!=(const Fruit &other) const;

    bool operator<(const Fruit &other) const;

    bool operator>(const Fruit &other) const;

    bool operator<=(const Fruit &other) const;

    bool operator>=(const Fruit &other) const;
};