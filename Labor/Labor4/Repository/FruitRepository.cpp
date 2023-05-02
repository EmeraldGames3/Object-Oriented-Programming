#include <algorithm>
#include "FruitRepository.h"

Repository::FruitRepository::FruitRepository(string _fileName) : fileName(std::move(_fileName)) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to create database file: " + fileName);
    }

    data = std::make_shared<vector<Fruit>>();

    string line;
    while (std::getline(file, line)) {
        Fruit fruit = convertFromString(line);
        data->push_back(fruit);
    }

    file.close();
}

void Repository::FruitRepository::writeToDataBase() {
    std::ofstream file(fileName, std::ios::trunc);

    string fileData{};
    for (auto it = data->begin(); it != data->end(); ++it) {
        fileData += (it->getFruitAsFormattedString());
        if (it != data->end() - 1) {
            fileData += '\n';
        }
    }

    file << fileData;

    file.close();
}

void Repository::FruitRepository::addFruit(const Fruit &fruit) {
    data->push_back(fruit);
}

void Repository::FruitRepository::deleteFruit(const Fruit &fruit) {
    auto it = std::find_if(data->begin(), data->end(), [&](const Fruit& f){
        return f.getName() == fruit.getName();
    });
    if (it != data->end()) {
        data->erase(it);
    }
}

shared_ptr<vector<Fruit>> Repository::FruitRepository::getAll() {
    return data;
}

void Repository::FruitRepository::deleteData() {
    data = std::make_unique<vector<Fruit>>();
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

string Repository::FruitRepository::convertToString(Fruit &fruit) {
    return fruit.getFruitAsFormattedString();
}