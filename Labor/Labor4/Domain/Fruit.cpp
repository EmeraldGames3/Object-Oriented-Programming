#include "Fruit.h"

///Name getter
string Fruit::getName() {
    return name;
}

///Origin getter
string Fruit::getOrigin() {
    return origin;
}

///Price getter
int Fruit::getPrice() const {
    return price;
}

///Price setter
void Fruit::setPrice(int newPrice) {
    price = newPrice;
}
