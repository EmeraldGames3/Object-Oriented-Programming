#include "FruitController.h"

Controller::FruitController::FruitController(const string &fileName) : fruitRepository(fileName) {
    fruits = fruitRepository.getAll();
}

void Controller::FruitController::addFruit(const string &name, const string &origin, const string &producer,
                                           const Time::Date &expiryDate, int quantity, float price) {
    Fruit newFruit(name, origin, producer, expiryDate, quantity, price);
    bool exists = false;

    for (auto &it: *fruits) {
        if (it == newFruit) {
            it.setQuantity(it.getQuantity() + newFruit.getQuantity());
            exists = true;

            float oldPrice = it.getPrice();
            int oldQuantity = it.getQuantity() - newFruit.getQuantity();
            float newPrice = newFruit.getPrice();
            int newQuantity = newFruit.getQuantity();
            float avgPrice = (oldPrice * float(oldQuantity) + newPrice * float(newQuantity)) /
                             float((oldQuantity + newQuantity)); //calculate the median price
            it.setPrice(avgPrice);

            // Update expiry date to the closest one
            if (it.getExpirationDate() > newFruit.getExpirationDate()) {
                it.setExpirationDate(expiryDate);
            }
            break;
        }
    }

    if (!exists) {
        fruitRepository.addFruit(newFruit);
    }
}

void Controller::FruitController::deleteFruit(const string& name, const string& origin) {
    Fruit tempFruit(name, origin);
    bool found = false;
    for (auto &it : *fruits) {
        if (it == tempFruit) {
            fruitRepository.deleteFruit(it);
            found = true;
            break;
        }
    }
    if (!found) {
        throw std::runtime_error("Fruit not found");
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

void Controller::FruitController::saveData() {
    fruitRepository.writeToDataBase();
}
