#include <algorithm>
#include "FruitRepository.h"

///Constructor
///@throws runtime_error if the file is not found
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

///write to the database the modified data
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

///Add a fruit
void Repository::FruitRepository::addFruit(const Fruit &fruit) {
    data->push_back(fruit);
}

///Delete a fruit
void Repository::FruitRepository::deleteFruit(const Fruit &fruit) {
    auto it = std::find_if(data->begin(), data->end(), [&](const Fruit& f){
        return f.getName() == fruit.getName();
    });
    if (it != data->end()) {
        data->erase(it);
    }
}

///Get all fruits from DataBase
shared_ptr<vector<Fruit>> Repository::FruitRepository::getAll() {
    return data;
}

///Delete all the data from the DataBase
void Repository::FruitRepository::deleteData() {
    data = std::make_unique<vector<Fruit>>();
}

///Convert a string into a fruit
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

///Convert a fruit into a string
string Repository::FruitRepository::convertToString(Fruit &fruit) {
    return fruit.getFruitAsFormattedString();
}