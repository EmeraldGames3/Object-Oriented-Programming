#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <list>
#include "../Domain/Domain.h"

using std::string, std::shared_ptr, std::list, Domain::Fruit;

namespace Repository{
    class FruitRepository{
    private:
        string dataBase;
        shared_ptr<list<Fruit>> data;

    public:
        ///Constructor
        explicit FruitRepository(const string &_dataBase);

        ///Copy constructor
        FruitRepository(const FruitRepository &fruitRepository) = default;

        ///Assignment operator
        FruitRepository &operator=(const FruitRepository &other) = default;

        ///Destructor
        ~FruitRepository() = default;

        ///Data interactions
        void addFruit(const Fruit &fruit);
        void deleteFruit(const Fruit &fruit);
        shared_ptr<list<Fruit>> getAll();

        ///Update the DataBase
        void writeToDataBase();

    private:
        ///Convert the data to a string
        static string convertToString(Fruit fruit);

        ///Convert a Fruit to a string
        static Fruit convertFromString(const string &fruit);
    };
}