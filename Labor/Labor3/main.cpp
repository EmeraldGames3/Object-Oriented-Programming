#include <iostream>
#include <cassert>
#include "DependancyStructuredMatrix.h"

void testConstructors() {
    DSM<int> dsm1(10);

    // Test default constructor
    assert(dsm1.size() == 10);
    assert(dsm1.getCapacity() == 21);

    // Test constructor with element names
    string elementNames[4] = {"a", "b", "c", "d"};
    DSM<int> dsm2(elementNames, 4);
    assert(dsm2.size() == 4);
    assert(dsm2.getCapacity() == 9);

    // Test copy constructor
    DSM<int> dsm3 = dsm2;
    assert(dsm3.size() == 4);
    assert(dsm3.getCapacity() == 9);
}

void test_getName() {
    string elementNames[] = {"apple", "banana", "cherry", "date", "elderberry"};
    DSM<int> dsm(elementNames, 5);

    // Test getting a valid element name
    assert(dsm.getName(0) == "apple");
    assert(dsm.getName(2) == "cherry");
    assert(dsm.getName(4) == "elderberry");

    // Test getting an invalid index
    try {
        dsm.getName(-1);
        assert(false); // should have thrown an exception
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Invalid index");
    }
    try {
        dsm.getName(5);
        assert(false); // should have thrown an exception
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Invalid index");
    }
}

void testSetElementName() {
    DSM<int> dsm(3);

    // Test setting a valid index
    dsm.setElementName(0, "element 0");
    assert(dsm.getName(0) == "element 0");

    // Test setting an invalid index
    try {
        dsm.setElementName(3, "element 3");
        assert(false); // should not get here
    } catch (const std::invalid_argument& e) {
        assert(e.what() == std::string("Invalid index"));
    }
}

void testResizeElementNames() {
    DSM<int> dsm(3);
    dsm.setElementName(0, "foo");
    dsm.setElementName(1, "bar");
    dsm.setElementName(2, "baz");

    // Test resizing to a larger capacity
    dsm.resizeElementNames(5);
    assert(dsm.getCapacity() == 5);
    assert(dsm.size() == 3);
    assert(dsm.getName(0) == "foo");
    assert(dsm.getName(1) == "bar");
    assert(dsm.getName(2) == "baz");

    // Test resizing to a smaller capacity
    try {
        dsm.resizeElementNames(1);
        assert(false);
    } catch (const std::out_of_range& e) {
        assert(string(e.what()) == "Index out of range");
    }

    // Test resizing to the same capacity
    dsm.resizeElementNames(3);
    assert(dsm.getCapacity() == 3);
    assert(dsm.size() == 3);
    assert(dsm.getName(0) == "foo");
    assert(dsm.getName(1) == "bar");
    assert(dsm.getName(2) == "baz");
}

void testAddLinkShort() {
    //Check if the addLink function adds the Elements correctly

    DSM<int> dsm;
    dsm.addLink("A", "B", 10);
    dsm.addLink("B", "C", 20);

    // Check that elements were added correctly
    assert(dsm.getName(0) == "A");
    assert(dsm.getName(1) == "B");
    assert(dsm.getName(2) == "C");

    // Check that adding a link with non-existent elements adds the elements
    dsm.addLink("D", "E", 40);
    assert(dsm.getName(3) == "D");
    assert(dsm.getName(4) == "E");
}

void testAddLinkExtended(){
    DSM<int> dsm(3);

    // Adding a link between two existing elements
    dsm.setElementName(0,"A");
    dsm.setElementName(1, "B");
    dsm.addLink("A", "B", 5);
    assert(dsm.hasLink("A", "B"));
    assert(dsm.linkWeight("A", "B") == 5);

    // Adding a link with new elements
    dsm.addLink("C", "D", 10);
    assert(dsm.hasElement("C"));
    assert(dsm.hasElement("D"));
    assert(dsm.hasLink("C", "D"));
    assert(dsm.linkWeight("C", "D") == 10);

    // Deleting a link
    dsm.deleteLink("A", "B");
    assert(!dsm.hasLink("A", "B"));
}

int main() {
    DSM<int> test1(3);
    DSM<float> test2(3);
    DSM<double> test3(3);
    DSM<bool> test4(3);

    testConstructors();
    test_getName();
    testSetElementName();
    testResizeElementNames();
    testAddLinkShort();
//    testAddLinkExtended();
    return 0;
}
