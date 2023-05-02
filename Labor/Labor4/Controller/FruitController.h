#pragma once

#include "../Domain/Domain.h"
#include "../Repository/Repository.h"
#include "../Time/Time.h"
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

using Domain::Fruit, Repository::FruitRepository, Time::Date, std::vector, std::shared_ptr, std::string, std::unique_ptr;

namespace Controller {
    class FruitController {
    private:
        FruitRepository fruitRepository;
        shared_ptr<vector<Fruit>> fruits;

    public:
        ///Constructor
        explicit FruitController(const string &fileName = "Repository/Data/DataBase");

        ///Copy constructor
        FruitController(const FruitController &fruitController) = default;

        ///Assignment operator
        FruitController &operator=(const FruitController &fruitController) = default;

        ///Destructor
        ~FruitController() = default;

        ///Data Manipulation
        void addFruit(const string &name, const string &origin, const string &producer, const Time::Date &expiryDate,
                      int quantity, float price);
        void deleteFruit(const string &name, const string &origin);
        void saveData();
        unique_ptr<vector<Fruit>> getAllFruits();
        unique_ptr<vector<Fruit>> findFruits(const string &searchString);
    };
}