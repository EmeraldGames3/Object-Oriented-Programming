#include "Fruit.h"

#include <utility>

using Domain::Fruit;

///Default constructor
///@warning The strings given to this constructor are moved to another address in memory
///It is unsafe to access them after this constructor has been called
Fruit::Fruit(string _name, string _origin, string _producer, const Date &_expirationDate,
             int _quantity, int _price) : name{std::move(_name)},
                                          origin{std::move(_origin)},
                                          producer{std::move(_producer)},
                                          expirationDate(_expirationDate),
                                          quantity{_quantity},
                                          price{_price} {}

///Name getter
string Fruit::getName() const {
    return name;
}

///Origin getter
string Fruit::getOrigin() const {
    return origin;
}

///Get producer
string Fruit::getProducer() const {
    return producer;
}

///Price getter
int Fruit::getPrice() const {
    return price;
}

///ExpirationDate getter
Date Fruit::getExpirationDate() const {
    return expirationDate;
}

///Quantity getter
int Fruit::getQuantity() const {
    return quantity;
}

///Name setter
void Fruit::setName(const string &newName) {
    name = newName;
}

///Origin setter
void Fruit::setOrigin(const string &newOrigin) {
    origin = newOrigin;
}

///Producer setter
void Fruit::setProducer(const string &newProducer) {
    producer = newProducer;
}

///ExpirationDate setter
void Fruit::setExpirationDate(const Date &newExpirationDate) {
    expirationDate = newExpirationDate;
}

///Quantity setter
void Fruit::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

///Price setter
void Fruit::setPrice(int newPrice) {
    price = newPrice;
}

bool Domain::Fruit::operator==(const Fruit& other) const {
    return (name == other.name) && (producer == other.producer);
}

bool Domain::Fruit::operator!=(const Fruit& other) const {
    return !(*this == other);
}

bool Domain::Fruit::operator<(const Fruit& other) const {
    return expirationDate < other.expirationDate;
}

bool Domain::Fruit::operator>(const Fruit& other) const {
    return expirationDate > other.expirationDate;
}

bool Domain::Fruit::operator<=(const Fruit& other) const {
    return (*this < other) || (*this == other);
}

bool Fruit::operator>=(const Fruit &other) const {
    return (*this > other) || (*this == other);
}