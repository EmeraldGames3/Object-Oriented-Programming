#pragma once

#include "Time.h"
#include "Domain.h"
#include "Controller.h"

using Time::Date;
using Domain::Fruit;
using Controller::FruitController;

namespace UI{
    class UserInterface{
    private:
        FruitController controller{};

    public:
        ///Run the programme
        void run();

        ///Constructor
        UserInterface() = default;

        ///Copy constructor
        UserInterface(const UserInterface &userInterface) = default;

        ///Destructor
        ~UserInterface() = default;

    private:
        ///Display the UI menu
        static void displayMenu();

        ///Manipulate data and display it if needed
        void addProduct();
        void removeProduct();
        void displayProductsByString();
        void displayLowQuantityProducts();
        void displayProductsByExpirationDate();
    };
}

