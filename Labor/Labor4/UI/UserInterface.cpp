#include "UserInterface.h"
#include <iostream>

using std::cin, std::cout;

void UI::UserInterface::run() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 0:
                cout << "Exiting program...\n";
                break;
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                displayProductsByString();
                break;
            case 5:
                displayLowQuantityProducts();
                break;
            case 6:
                displayProductsByExpirationDate();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}

void UI::UserInterface::displayMenu() {
    cout << "\nFruit Store Management System\n\n"
         << "1. Add a product\n"
         << "2. Update a product\n"
         << "3. Remove a product\n"
         << "4. Display products containing a certain string\n"
         << "5. Display products with low quantity\n"
         << "6. Display products sorted by expiration date\n"
         << "0. Exit\n\n"
         << "Enter your choice: ";
}

void UI::UserInterface::addProduct() {
    std::string name, origin, producer;
    int price, quantity, year, month, day;

    std::cout << "Enter product name: ";
    std::cin >> name;

    std::cout << "Enter product origin: ";
    std::cin >> origin;

    std::cout << "Enter product producer: ";
    std::cin >> producer;

    std::cout << "Enter product price: ";
    std::cin >> price;

    std::cout << "Enter product quantity: ";
    std::cin >> quantity;

    std::cout << "Enter product expiration date (year month day): ";
    std::cin >> year >> month >> day;

    while (year < 2023 || year > 2043 || month < 1 || month > 12 || day < 1 || day > Date::daysInMonth(year, month)) {
        std::cout << "Invalid date. Please enter a valid expiration date (year month day): ";
        std::cin >> year >> month >> day;
    }

    std::cout << '\n';

    Date expirationDate(year, month, day);
    Fruit new_fruit(name, origin, producer, expirationDate, quantity, price);

    try {

        std::cout << "Product added successfully." << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void UI::UserInterface::updateProduct() {
    std::string name, origin, producer;
    int price, quantity, year, month, day;

    std::cout << "Enter product name: ";
    std::cin >> name;

    std::cout << "Enter product origin: ";
    std::cin >> origin;

    std::cout << "Enter product producer: ";
    std::cin >> producer;

    std::cout << "Enter product price: ";
    std::cin >> price;

    std::cout << "Enter product quantity: ";
    std::cin >> quantity;

    std::cout << "Enter product expiration date (year month day): ";
    std::cin >> year >> month >> day;

    while (year < 2023 || year > 2043 || month < 1 || month > 12 || day < 1 || day > Date::daysInMonth(year, month)) {
        std::cout << "Invalid date. Please enter a valid expiration date (year, month, day): ";
        std::cin >> year >> month >> day;
    }

    std::cout << '\n';

    Date expirationDate(year, month, day);
    Fruit new_fruit(name, origin, producer, expirationDate, quantity, price);

    try {

        std::cout << "Product added successfully." << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void UI::UserInterface::removeProduct() {
    std::string name, origin;

    std::cout << "Enter product name: ";
    std::cin >> name;

    std::cout << "Enter product origin: ";
    std::cin >> origin;

    try {
        // TODO implement
        std::cout << "Product removed successfully." << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void UI::UserInterface::displayProductsByString() {
    std::string query;

    std::cout << "Enter search query: ";
    std::cin >> query;

    try {

    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void UI::UserInterface::displayLowQuantityProducts() {
    int quantity;

    std::cout << "Enter quantity threshold: ";
    std::cin >> quantity;

    try {

    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void UI::UserInterface::displayProductsByExpirationDate() {

}