#pragma once

#include "../Domain/Domain.h"
#include "../Repository/Repository.h"
#include "../Time/Time.h"
#include <memory>
#include <vector>
#include <string>

using Domain::Fruit, Repository::FruitRepository, Time::Date, std::vector, std::shared_ptr, std::string;

namespace Controller{
    class FruitController{
    private:
        FruitRepository fruitRepository;
        shared_ptr<vector<Fruit>> fruits;

    public:
        ///Constructor
        explicit FruitController(const string &fileName);

        ///Copy constructor
        FruitController(const FruitController &fruitController) = default;

        ///Assignment operator
        FruitController &operator=(const FruitController &fruitController) = default;

        ///Destructor
        ~FruitController() = default;
    };
}