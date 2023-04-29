#include "FruitRepository.h"

Repository::FruitRepository::FruitRepository(const string &_dataBase) : dataBase(_dataBase){
    std::ifstream file(dataBase);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to create database file: " + dataBase);
    }

    data = std::make_shared<list<Fruit>>();

    string line;
    std::getline(file, line); //Discard the first line

    while (std::getline(file, line)) {
        Fruit fruit = convertFromString(line);
        data->push_back(fruit);
    }
}

Domain::Fruit Repository::FruitRepository::convertFromString(const string &fruit) {
    std::stringstream ss(fruit);
    string name, origin, producer, expDateStr;
    int quantity;
    float price;
    char delim;

    std::getline(ss, name, ',');
    std::getline(ss, origin, ',');
    std::getline(ss, producer, ',');
    std::getline(ss, expDateStr, ',');
    ss >> quantity >> delim >> price;

    // Parse the expiration date string to a Date object
    std::istringstream iss(expDateStr);
    int year, month, day;
    iss >> year >> delim >> month >> delim >> day;
    Time::Date expirationDate(year, month, day);

    return Domain::Fruit(name, origin, producer, expirationDate, quantity, price);
}

void Repository::FruitRepository::addFruit(const Fruit &fruit) {
    data->push_back(fruit);
}

void Repository::FruitRepository::deleteFruit(const Fruit &fruit) {
    auto it = std::find(data->begin(), data->end(), fruit);
    if (it != data->end()) {
        data->erase(it);
    }
}

shared_ptr<list<Fruit>> Repository::FruitRepository::getAll() {
    return data;
}