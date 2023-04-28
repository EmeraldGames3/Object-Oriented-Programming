#pragma once

#include "../Time/Date/Date.h"
#include <string>

using std::string, Time::Date;

namespace Domain {
    class Fruit {
    private:
        string name;
        string origin;
        string producer;
        Date expirationDate;
        int quantity;
        int price;

    public:
        ///Default Constructor
        explicit Fruit(string _name, string _origin = "Romania", string _producer = "Nel",
                       const Date &_expirationDate = Date(2024, 1, 1),
                       int _quantity = 1, int _price = 1);

        ///Copy constructor
        Fruit(const Fruit &other) = default;

        ///Destructor
        ~Fruit() = default;

        ///Getters
        string getName() const;
        string getOrigin() const;
        string getProducer() const;
        Date getExpirationDate() const;
        [[nodiscard]] int getQuantity() const;
        [[nodiscard]] int getPrice() const;

        ///Setters
        void setName(const string &newName);
        void setOrigin(const string &newOrigin);
        void setProducer(const string &newProducer);
        void setExpirationDate(const Date &newExpirationDate);
        void setQuantity(int newQuantity);
        void setPrice(int newPrice);

        ///Overloaded operators
        Fruit &operator=(const Fruit &other) = default;
        bool operator==(const Fruit &other) const;
        bool operator!=(const Fruit &other) const;
        bool operator<(const Fruit &other) const;
        bool operator>(const Fruit &other) const;
        bool operator<=(const Fruit &other) const;
        bool operator>=(const Fruit &other) const;
    };
}