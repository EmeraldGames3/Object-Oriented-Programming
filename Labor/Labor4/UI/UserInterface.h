#pragma once

#include "../Time/Time.h"
#include "../Domain/Domain.h"
#include "../Controller/Controller.h"

using Time::Date;
using Domain::Fruit;
using Controller::FruitController;

namespace UI{
    class UserInterface{
    private:
        FruitController controller{};

    public:
        void run();

    private:
        static void displayMenu();
        void addProduct();
        void removeProduct();
        void displayProductsByString();
        void displayLowQuantityProducts();
        void displayProductsByExpirationDate();
    };
}

