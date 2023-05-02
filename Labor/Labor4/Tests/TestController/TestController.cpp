#include "TestController.h"

#include <cassert>
#include <iostream>

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

void testAddFruit(){
    FruitController controller("Repository/Data/testDataBase1");

    // Add some fruits
    controller.addFruit("Apple", "USA", "John Smith", Date(2023, 5, 1), 10, 1.5);
    controller.addFruit("Banana", "Brazil", "Maria Garcia", Date(2023, 5, 3), 5, 2.0);
    controller.addFruit("Pineapple", "Costa Rica", "Pedro Perez", Date(2023, 5, 5), 3, 3.0);

    // Try to add a fruit that already exists
    controller.addFruit("Apple", "USA", "John Smith", Date(2023, 5, 2), 20, 2.0);

    // Check that the fruit was updated with the correct quantity and price
    Fruit apple = controller.getAllFruits()->front();

    assert(apple.getQuantity() == 30);
    assert(std::abs(apple.getPrice() - 1.75) < 0.1);
}

void testDeleteFruit() {
    FruitController fc("Repository/Data/testDataBase1");
    fc.addFruit("apple", "USA", "Farmer John", Date(2023, 5, 31), 10, 1.50);
    fc.addFruit("banana", "Brazil", "Fruit Co.", Date(2023, 6, 15), 20, 0.50);

    // Test deleting existing fruit
    fc.deleteFruit("apple", "USA");
    assert(fc.getAllFruits()->size() == 1);

    // Test deleting non-existing fruit
    try {
        fc.deleteFruit("orange", "Spain");
    } catch (std::exception& e) {
        assert(std::string(e.what()) == "Fruit not found");
    }

    // Make sure the other fruit is still there
    assert(fc.getAllFruits()->size() == 1);
    assert(fc.getAllFruits()->at(0).getName() == "banana");
}


void testController() {
    testControllerConstructor();
    testAddFruit();
    testDeleteFruit();
}