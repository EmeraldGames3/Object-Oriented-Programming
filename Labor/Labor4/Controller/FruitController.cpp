#include "FruitController.h"

Controller::FruitController::FruitController(const string &fileName) : fruitRepository(fileName) {
    fruits = fruitRepository.getAll();
}

void Controller::FruitController::addFruit(const string &name, const string &origin, const string &producer,
                                           const Time::Date &expiryDate, int quantity, float price) {
    fruitRepository.addFruit(Fruit(name, origin, producer, expiryDate, quantity, price));
}

void Controller::FruitController::deleteFruit(const string &name, const string &origin) {
    Fruit tempFruit(name, origin);
    for (const auto &it: *fruits) {
        if (it == tempFruit)
            fruitRepository.deleteFruit(it);
    }
}

unique_ptr<vector<Fruit>> Controller::FruitController::getAllFruits() {
    auto sortedFruits = std::make_unique<vector<Fruit>>(*fruits);
    std::sort(sortedFruits->begin(), sortedFruits->end(),
              [](const Fruit &a, const Fruit &b) -> bool {
                  return a.getName() < b.getName();
              }
    );
    return sortedFruits;
}

unique_ptr<vector<Fruit>> Controller::FruitController::findFruits(const string &searchString) {
    auto result = std::make_unique<vector<Fruit>>();

    if (searchString.empty())
        return getAllFruits();

    for (const auto &it: *fruits) {
        if (it.getName().find(searchString) != std::string::npos)
            result->push_back(it);
    }

    std::sort(result->begin(), result->end(),
              [](const Fruit &a, const Fruit &b) -> bool {
                  return a.getName() < b.getName();
              }
    );

    return result;
}