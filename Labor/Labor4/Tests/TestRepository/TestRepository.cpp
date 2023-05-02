#include "TestRepository.h"
#include <cassert>
#include <string>
#include <iostream>

void testFruitParsing() {
    // Test convertFromString()
    std::string fruitString = "Apple,USA,Red Del,2023-05-01,10,1.50";
    Fruit fruit = Repository::FruitRepository::convertFromString(fruitString);
    assert(fruit.getName() == "Apple");
    assert(fruit.getOrigin() == "USA");
    assert(fruit.getProducer() == "Red Del");
    assert(fruit.getExpirationDate().getDateAsFormattedString() == "2023-5-1");
    assert(fruit.getQuantity() == 10);
    assert(fruit.getPrice() == 1.5f);

    // Test convertToString()
    string expectedFruitString = "Apple,USA,Red Del,2023-5-1,10,1.50";
    string actualFruitString = Repository::FruitRepository::convertToString(fruit);

    assert(actualFruitString == expectedFruitString);
}

void testConstructor() {
    //Try creating an invalid fruit Repository
    try {
        Repository::FruitRepository fruitRepository("invalid");
        assert(false);
    } catch (const std::runtime_error &exception) {
        assert(true);
    }

    {
        //Create a repository with no data
        Repository::FruitRepository fruitRepository("Repository/Data/testDataBase1");
        assert(fruitRepository.getAll()->empty());
    }

    {
        //Create a valid repository
        Repository::FruitRepository fruitRepository("Repository/Data/testDataBase2");
        Fruit expectedFruit1("Apple", "USA", "Apple Inc.",
                             Time::Date(2023, 5, 1), 10, 1.0);
        Fruit expectedFruit2("Banana", "Ecuador", "Fruit Co.",
                             Time::Date(2023, 4, 30), 5, 2.0);


        assert(fruitRepository.getAll()->size() == 2);
        assert(fruitRepository.getAll()->front() == expectedFruit1);
        assert(fruitRepository.getAll()->back() == expectedFruit2);
    }
}

void testAddAndDeleteFruits() {
    // Create a new repository
    Repository::FruitRepository fruitRepo("Repository/Data/testDataBase1");

    // Create some sample fruits
    Domain::Fruit apple("Apple", "USA", "Apple Inc.",
                        Time::Date(2023, 5, 1), 10, 1);
    Domain::Fruit banana("Banana", "Ecuador", "Fruit Co.",
                         Time::Date(2023, 4, 30), 5, 2);
    Domain::Fruit kiwi("Kiwi", "New Zealand", "Kiwi Farms",
                       Time::Date(2023, 5, 10), 15, 3);

    // Add the first fruit to the repository
    fruitRepo.addFruit(apple);

    // Check that the fruit was added
    auto allFruits = fruitRepo.getAll();
    assert(allFruits->size() == 1);
    assert(allFruits->at(0) == apple);

    // Add the second fruit to the repository
    fruitRepo.addFruit(banana);

    // Check that both fruits were added
    allFruits = fruitRepo.getAll();
    assert(allFruits->size() == 2);
    assert(allFruits->at(0) == apple);
    assert(allFruits->at(1) == banana);

    // Delete the first fruit from the repository
    fruitRepo.deleteFruit(apple);

    // Check that the fruit was deleted
    allFruits = fruitRepo.getAll();
    assert(allFruits->size() == 1);
    assert(allFruits->at(0) == banana);

    // Delete the second fruit from the repository
    fruitRepo.deleteFruit(banana);

    // Check that the repository is empty
    allFruits = fruitRepo.getAll();
    assert(allFruits->empty());

    // Add a new fruit and then delete it
    fruitRepo.addFruit(kiwi);
    allFruits = fruitRepo.getAll();
    assert(allFruits->size() == 1);
    assert(allFruits->at(0) == kiwi);

    fruitRepo.deleteFruit(kiwi);
    allFruits = fruitRepo.getAll();
    assert(allFruits->empty());
}

void testDeleteData() {
    Repository::FruitRepository fruitRepository("Repository/Data/testDataBase2");
    fruitRepository.deleteData();
    assert(fruitRepository.getAll()->empty());
}

void testWriteToDataBase() {
    Repository::FruitRepository repo("Repository/Data/testDataBase3");
    repo.deleteData();

    repo.addFruit(Domain::Fruit("Apple", "USA", "Apple Inc.",
                                Time::Date(2023, 5, 1), 10, 1));
    repo.addFruit(Domain::Fruit("Banana", "Ecuador", "Fruit Co.",
                                Time::Date(2023, 4, 30), 5, 2));
    repo.writeToDataBase();

    std::ifstream file("Repository/Data/testDataBase3");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContents = buffer.str();
    file.close();

    std::string expectedOutput = "Apple,USA,Apple Inc.,2023-5-1,10,1.00\nBanana,Ecuador,Fruit Co.,2023-4-30,5,2.00";
    assert(fileContents == expectedOutput);
}

void testRepository() {
    testFruitParsing();
    testConstructor();
    testAddAndDeleteFruits();
    testDeleteData();
    testWriteToDataBase();
}