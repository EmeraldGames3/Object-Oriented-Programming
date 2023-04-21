#include "Fruit.h"

using Domain::Fruit;

#pragma GCC diagnostic ignored "-Wpessimizing-move"
//Disable warning

///Default constructor
Fruit::Fruit(const string &_name, const string &_origin, const string &_producer, const Date &_expirationDate,
             int _quantity, int _price) : name{_name},
                                          origin{_origin},
                                          producer{_producer},
                                          expirationDate(_expirationDate),
                                          quantity{_quantity},
                                          price{_price} {}

#pragma GCC diagnostic warning "-Wpessimizing-move"
//Reenable warning

///Name getter
string Fruit::getName() {
    return name;
}

///Origin getter
string Fruit::getOrigin() {
    return origin;
}

///Get producer
string Fruit::getProducer() {
    return producer;
}

///Price getter
int Fruit::getPrice() const {
    return price;
}

///ExpirationDate getter
Date Fruit::getExpirationDate() {
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