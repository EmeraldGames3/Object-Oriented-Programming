#include "Fruit.h"

#include <utility>

using Domain::Fruit;

///Default constructor
///@warning The strings given to this constructor are moved to another address in memory
///It is unsafe to access them after this constructor has been called
Fruit::Fruit(string _name, string _origin, string _producer, const Date &_expirationDate,
             int _quantity, float _price) : name{std::move(_name)},
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
float Fruit::getPrice() const {
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

///Get the fruit as string
std::string Domain::Fruit::getFruitAsFormattedString() {
    //Format the price to 2 decimal points
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << price;
    std::string formattedPrice = stream.str();

    return name + ',' + origin + ',' + producer + ',' + expirationDate.getDateAsFormattedString() + ',' +
           std::to_string(quantity) + ',' + formattedPrice;
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
void Fruit::setPrice(float newPrice) {
    price = newPrice;
}

///Overloaded comparison operators ///
bool Domain::Fruit::operator==(const Fruit& other) const {
    return (name == other.name) && (origin == other.origin);
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

///Overloaded cout for the Fruit class
std::ostream &Domain::operator<<(std::ostream &os, const Fruit &fruit) {
    os << "Name: " + fruit.name + "\n";
    os << "Origin: " + fruit.origin + "\n";
    os << "Producer: " + fruit.producer + "\n";
    os << "Expiration Date: " + fruit.expirationDate.getDateAsFormattedString() + "\n";
    os << "Quantity: " + std::to_string(fruit.quantity) + "\n";
    os << "Price: " + std::to_string(fruit.price) + "\n";
    return os;
}


