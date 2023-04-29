#include "TestController.h"

#include <cassert>

void testControllerConstructor() {
    //Test empty Data Base
    {
        FruitController fruitController("Repository/Data/testDataBase1");
        assert(fruitController.getAllFruits()->empty());
    }
    //Test valid Data Base
    {
        FruitController fruitController("Repository/Data/testDataBase2");
        assert(fruitController.getAllFruits()->size() == 2);
        assert(fruitController.getAllFruits()->front() == Fruit("Apple", "USA"));
        assert(fruitController.getAllFruits()->back() == Fruit("Banana", "Ecuador"));
    }
}

void testController() {
    testControllerConstructor();
}