#include "TestController.h"

#include <cassert>
#include <iostream>

void testControllerConstructor() {
    //Test empty Data Base
    {
        FruitController fruitController("testDataBase1");
        assert(fruitController.getAllFruits()->empty());
    }
    //Test valid Data Base
    {
        FruitController fruitController("testDataBase2");
        assert(fruitController.getAllFruits()->size() == 2);
        assert(fruitController.getAllFruits()->front() == Fruit("Apple", "USA"));
        assert(fruitController.getAllFruits()->back() == Fruit("Banana", "Ecuador"));
    }
}

void testAddFruit() {
    FruitController controller("testDataBase1");

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
    FruitController fc("testDataBase1");
    fc.addFruit("apple", "USA", "Farmer John", Date(2023, 5, 31), 10, 1.50);
    fc.addFruit("banana", "Brazil", "Fruit Co.", Date(2023, 6, 15), 20, 0.50);

    // Test deleting existing fruit
    fc.deleteFruit("apple", "USA");
    assert(fc.getAllFruits()->size() == 1);

    // Test deleting non-existing fruit
    try {
        fc.deleteFruit("orange", "Spain");
    } catch (std::exception &e) {
        assert(std::string(e.what()) == "Fruit not found");
    }

    // Make sure the other fruit is still there
    assert(fc.getAllFruits()->size() == 1);
    assert(fc.getAllFruits()->at(0).getName() == "banana");
}

void testSortByExpirationDate() {
    FruitController controller("testDataBase1");

    // Create some fruits
    Fruit apple("Apple", "USA", "Apple Inc", Time::Date(2023, 5, 1), 10, 1.00);
    Fruit banana("Banana", "Ecuador", "Fruit Co", Time::Date(2023, 4, 30), 5, 2.00);
    Fruit orange("Orange", "Spain", "Orchard Farm", Time::Date(2023, 5, 5), 8, 0.75);

    // Add the fruits to the controller
    controller.addFruit(apple.getName(), apple.getOrigin(), apple.getProducer(), apple.getExpirationDate(),
                        apple.getQuantity(), apple.getPrice());
    controller.addFruit(banana.getName(), banana.getOrigin(), banana.getProducer(), banana.getExpirationDate(),
                        banana.getQuantity(), banana.getPrice());
    controller.addFruit(orange.getName(), orange.getOrigin(), orange.getProducer(), orange.getExpirationDate(),
                        orange.getQuantity(), orange.getPrice());

    // Get the fruits sorted by expiration date
    auto fruitsByExpiration = controller.getFruitsByExpirationDate();

    // Test that the first fruit has the earliest expiration date
    assert(fruitsByExpiration->at(0).getName() == "Banana");

    // Test that the second fruit has the second-earliest expiration date
    assert(fruitsByExpiration->at(1).getName() == "Apple");

    // Test that the third fruit has the latest expiration date
    assert(fruitsByExpiration->at(2).getName() == "Orange");
}

void testGetLowQuantityFruits() {
    Controller::FruitController controller("testDataBase1");
    controller.addFruit("Apple", "USA", "Apple Inc",
                        Time::Date(2023, 5, 1), 10, 1.00);
    controller.addFruit("Banana", "Ecuador", "Fruit Co",
                        Time::Date(2023, 4, 30), 5, 2.00);
    controller.addFruit("Orange", "Spain", "Fruit Corp",
                        Time::Date(2023, 5, 10), 3, 1.50);
    controller.addFruit("Grape", "Italy", "Vineyards Ltd",
                        Time::Date(2023, 6, 1), 12, 0.75);

    auto lowQuantityFruits = controller.getLowQuantityFruits(6);

    assert(lowQuantityFruits->size() == 2);
    assert(lowQuantityFruits->front() == Fruit("Banana", "Ecuador") &&
           lowQuantityFruits->back() == Fruit("Orange", "Spain"));
}

void testFindFruits() {
    Controller::FruitController controller("testDataBase1");

    // Add some fruits to the controller
    controller.addFruit("Apple", "USA", "Apple Inc",
                        Date(2023, 5, 1), 10, 1.00);
    controller.addFruit("Banana", "Ecuador", "Fruit Co",
                        Date(2023, 4, 30), 5, 2.00);
    controller.addFruit("Orange", "Spain", "Orange Co",
                        Date(2023, 5, 5), 8, 1.50);
    controller.addFruit("Mango", "Mexico", "Mango Co",
                        Date(2023, 5, 2), 12, 2.50);

    // Search for fruits with name "an"
    auto result = controller.findFruits("an");

    // Check that the search returned the correct fruits
    assert(result->size() == 3);
    assert((*result)[0].getName() == "Banana");
    assert((*result)[1].getName() == "Mango");
    assert((*result)[2].getName() == "Orange");

    assert(*controller.findFruits("") == *controller.getAllFruits());
}

void testController() {
    testControllerConstructor();
    testAddFruit();
    testDeleteFruit();
    testSortByExpirationDate();
    testGetLowQuantityFruits();
    testFindFruits();
}