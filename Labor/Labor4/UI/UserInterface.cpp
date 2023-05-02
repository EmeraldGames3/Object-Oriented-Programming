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
                controller.saveData();
                break;
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayProductsByString();
                break;
            case 4:
                displayLowQuantityProducts();
                break;
            case 5:
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
         << "2. Remove a product\n"
         << "3. Display products containing a certain string\n"
         << "4. Display products with low quantity\n"
         << "5. Display products sorted by expiration date\n"
         << "0. Exit\n\n"
         << "Enter your choice: ";
}

void UI::UserInterface::addProduct() {
    std::string input;
    std::string name, origin, producer;
    int quantity, year, month, day;
    float price;

    std::cout << "Enter product name: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> name;

    std::cout << "Enter product origin: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> origin;

    std::cout << "Enter product producer: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> producer;

    std::cout << "Enter product price: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> price;

    std::cout << "Enter product quantity: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> quantity;

    std::cout << "Enter product expiration date (year month day): ";
    std::getline(std::cin, input);
    std::stringstream(input) >> year >> month >> day;

    while (year < 2023 || year > 2043 || month < 1 || month > 12 || day < 1 || day > Date::daysInMonth(year, month)) {
        std::cout << "Invalid date. Please enter a valid expiration date (year month day): ";
        std::getline(std::cin, input);
        std::stringstream(input) >> year >> month >> day;
    }

    std::cout << '\n';
    Date expirationDate(year, month, day);

    try {
        controller.addFruit(name, origin, producer, expirationDate, quantity, price);
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
        controller.deleteFruit(name, origin);
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
