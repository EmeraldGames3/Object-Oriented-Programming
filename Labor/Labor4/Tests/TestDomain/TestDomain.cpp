#include "TestDomain.h"

void testFruitConstructors() {
    // Test default constructor
    Fruit apple("Apple");
    assert(apple.getName() == "Apple");
    assert(apple.getOrigin() == "Romania");
    assert(apple.getProducer() == "Nel");
    assert(apple.getExpirationDate().getYear() == 2024);
    assert(apple.getExpirationDate().getMonth() == 1);
    assert(apple.getExpirationDate().getDay() == 1);
    assert(apple.getQuantity() == 1);
    assert(apple.getPrice() == 1);

    // Test copy constructor
    Fruit orange("Orange", "Spain", "Juan",
                 Date(2023, 12, 31), 10, 3);
    Fruit copiedOrange(orange);
    assert(copiedOrange.getName() == "Orange");
    assert(copiedOrange.getOrigin() == "Spain");
    assert(copiedOrange.getProducer() == "Juan");
    assert(copiedOrange.getExpirationDate().getYear() == 2023);
    assert(copiedOrange.getExpirationDate().getMonth() == 12);
    assert(copiedOrange.getExpirationDate().getDay() == 31);
    assert(copiedOrange.getQuantity() == 10);
    assert(copiedOrange.getPrice() == 3);
    // Modifying the copied object should not affect the original object
    copiedOrange.setQuantity(5);
    copiedOrange.setPrice(2);
    assert(orange.getQuantity() == 10);
    assert(orange.getPrice() == 3);

    // Test default parameters in constructor
    Fruit banana("Banana", "Ecuador");
    assert(banana.getName() == "Banana");
    assert(banana.getOrigin() == "Ecuador");
    assert(banana.getProducer() == "Nel");
    assert(banana.getExpirationDate().getYear() == 2024);
    assert(banana.getExpirationDate().getMonth() == 1);
    assert(banana.getExpirationDate().getDay() == 1);
    assert(banana.getQuantity() == 1);
    assert(banana.getPrice() == 1);

    // Test constructor with all parameters
    Fruit watermelon("Watermelon", "USA", "Bob",
                     Date(2023, 8, 15), 2, 8);
    assert(watermelon.getName() == "Watermelon");
    assert(watermelon.getOrigin() == "USA");
    assert(watermelon.getProducer() == "Bob");
    assert(watermelon.getExpirationDate().getYear() == 2023);
    assert(watermelon.getExpirationDate().getMonth() == 8);
    assert(watermelon.getExpirationDate().getDay() == 15);
    assert(watermelon.getQuantity() == 2);
    assert(watermelon.getPrice() == 8);
}

void testFruitGettersAndSetters() {
    Fruit apple("Apple", "USA", "John",
                Date(2023, 10, 31), 5, 2);

    // Test getters
    assert(apple.getName() == "Apple");
    assert(apple.getOrigin() == "USA");
    assert(apple.getProducer() == "John");
    assert(apple.getExpirationDate().getYear() == 2023);
    assert(apple.getExpirationDate().getMonth() == 10);
    assert(apple.getExpirationDate().getDay() == 31);
    assert(apple.getQuantity() == 5);
    assert(apple.getPrice() == 2);

    // Test setters
    apple.setName("Red Apple");
    apple.setOrigin("Canada");
    apple.setProducer("Alice");
    apple.setExpirationDate(Date(2024, 5, 15));
    apple.setQuantity(10);
    apple.setPrice(3);

    assert(apple.getName() == "Red Apple");
    assert(apple.getOrigin() == "Canada");
    assert(apple.getProducer() == "Alice");
    assert(apple.getExpirationDate().getYear() == 2024);
    assert(apple.getExpirationDate().getMonth() == 5);
    assert(apple.getExpirationDate().getDay() == 15);
    assert(apple.getQuantity() == 10);
    assert(apple.getPrice() == 3);

    // Test the copy assignment operator
    {
        Fruit fruit1("apple", "USA", "Apple Inc.", Date(2023, 12, 31), 10, 2);
        Fruit fruit2("orange", "Mexico", "Oranges S.A.", Date(2024, 1, 1), 5, 3);
        fruit1 = fruit2;

        assert(fruit1.getName() == "orange");
        assert(fruit1.getOrigin() == "Mexico");
        assert(fruit1.getProducer() == "Oranges S.A.");
        assert(fruit1.getExpirationDate() == Date(2024, 1, 1));
        assert(fruit1.getQuantity() == 5);
        assert(fruit1.getPrice() == 3);
    }

    // Test the equality operator
    {
        Fruit fruit1("apple", "USA", "Apple Inc.", Date(2023, 12, 31), 10, 2);
        Fruit fruit2("apple", "USA", "Apple Inc.", Date(2023, 12, 31), 5, 3);
        assert(fruit1 == fruit1); // A fruit is equal to itself
        assert(fruit1 == fruit2);
    }

    // Test the inequality operator
    {
        Fruit fruit1("apple", "USA", "Apple Inc.", Date(2023, 12, 31), 10, 2);
        Fruit fruit2("orange", "Mexico", "Oranges S.A.", Date(2024, 1, 1), 5, 3);
        assert(fruit1 != fruit2);
    }

    // Test the less than operator
    {
        Fruit fruit1("apple", "USA", "Apple Inc.", Date(2023, 12, 31), 10, 2);
        Fruit fruit2("orange", "Mexico", "Oranges S.A.", Date(2024, 1, 1), 5, 3);
        assert(fruit1 < fruit2);
    }

    // Test the greater than operator
    {
        Fruit fruit1("apple", "USA", "Apple Inc.", Date(2023, 12, 31), 10, 2);
        Fruit fruit2("orange", "Mexico", "Oranges S.A.", Date(2024, 1, 1), 5, 3);
        assert(fruit2 > fruit1);
    }

    // Test the less than or equal to operator
    {
        Fruit fruit1("apple", "USA", "Apple Inc.", Date(2023, 12, 31), 10, 2);
        Fruit fruit2("apple", "USA", "Apple Inc.", Date(2023, 12, 31), 5, 3);
        assert(fruit2 <= fruit1);
        assert(fruit1 <= fruit1);
    }

    // Test the greater than or equal to operator
    {
        Fruit fruit1("apple", "USA", "Apple Inc.", Date(2023, 12, 31), 10, 2);
        Fruit fruit2("orange", "Mexico", "Oranges S.A.", Date(2024, 1, 1), 5, 3);
        assert(fruit2 >= fruit1);
        assert(fruit1 >= fruit1);
    }
}

void testDomain(){
    testFruitConstructors();
    testFruitGettersAndSetters();
}