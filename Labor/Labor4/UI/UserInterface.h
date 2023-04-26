#pragma once

#include "../Time/Time.h"
#include "../Domain/Domain.h"

using Time::Date;
using Domain::Fruit;

namespace UI{
    class UserInterface{
    private:
//        FruitController controller;

    public:
        static void run();

    private:
        static void displayMenu();
        static void addProduct();
        static void updateProduct();
        static void removeProduct();
        static void displayProductsByString();
        static void displayLowQuantityProducts();
        static void displayProductsByExpirationDate();
    };
}

