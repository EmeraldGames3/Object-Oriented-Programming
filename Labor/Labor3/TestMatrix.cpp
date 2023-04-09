#include <iostream>
#include "TestMatrix.h"
#include "DependancyStructuredMatrix.h"

using std::cout;

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
    } catch (const std::invalid_argument &e) {
        assert(std::string(e.what()) == "Invalid index");
    }
    try {
        dsm.getName(5);
        assert(false); // should have thrown an exception
    } catch (const std::invalid_argument &e) {
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
    } catch (const std::invalid_argument &e) {
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
    } catch (const std::out_of_range &e) {
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

void testAddLink1() {
    //Check if the addLink function adds the Elements correctly

    DSM<int> dsm(2);
    dsm.setElementName(0, "A");
    dsm.setElementName(1, "B");

    dsm.addLink("A", "B", 10);
    dsm.addLink("C", "B", 20);
    assert(dsm.size() == 3);

    // Check that elements were added correctly
    assert(dsm.getName(0) == "A");
    assert(dsm.getName(1) == "B");
    assert(dsm.getName(2) == "C");
    assert(dsm.hasLink("A", "B"));
    assert(dsm.hasLink("C", "B"));

    // Check that adding a link with non-existent elements adds the elements
    dsm.addLink("D", "E", 40);
    assert(dsm.getName(3) == "D");
    assert(dsm.getName(4) == "E");
    assert(dsm.size() == 5);
    assert(dsm.hasLink("D", "E"));
}

void testAddLink2() {
    DSM<int> dsm(3);

    // Adding a link between two existing elements
    dsm.setElementName(0, "A");
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

void testResizeMatrix() {
    DSM<int> graph(3);

    // Resize the matrix and check that the capacity is correct
    graph.resizeMatrix(5);
    assert(graph.getCapacity() == 5);

    // Resize the matrix again with a smaller capacity and check for an exception
    try {
        graph.resizeMatrix(2);
        assert(false);
    } catch (const std::out_of_range &e) {
        assert(std::string(e.what()) == "Index out of range");
    }
}

void testGetIndex() {
    DSM<int> graph(3);

    // Add some element names
    graph.setElementName(0, "A");
    graph.setElementName(1, "B");
    graph.setElementName(2, "C");

    // Get the index of an element that exists in the DSM
    int indexA = graph.getIndex("A");
    assert(indexA == 0);

    // Get the index of an element that doesn't exist in the DSM
    int indexD = graph.getIndex("D");
    assert(indexD == -1);
}

void testAutomaticResize() {
    DSM<int> dsm(2);  // start with capacity 2
    dsm.setElementName(0, "A");
    dsm.setElementName(1, "B");
    dsm.addElementName("C");
    dsm.addElementName("D");
    dsm.addElementName("E");
    dsm.addElementName("F");
    dsm.addElementName("G");

    // Should resize to capacity 20
    assert(dsm.capacity == 20);
    assert(dsm.matrix[0][3] == 0);
    assert(dsm.matrix[1][3] == 0);
    assert(dsm.matrix[2][3] == 0);
    assert(dsm.matrix[3][0] == 0);
    assert(dsm.matrix[3][1] == 0);
    assert(dsm.matrix[3][2] == 0);

    dsm.removeElement("G");
    dsm.removeElement("F");
    dsm.removeElement("E");
    dsm.removeElement("D");
    dsm.removeElement("C");
    dsm.removeElement("B");

    // Should resize to capacity 5 again
    assert(dsm.capacity == 5);
    assert(dsm.matrix[0][1] == 0);
    assert(dsm.matrix[1][0] == 0);
}

void testDSM() {
    // Create a DSM for integers
    DSM<int> dsm(5);

    // Add some elements
    dsm.setElementName(0, "A");
    dsm.setElementName(1, "B");
    dsm.setElementName(2, "C");
    dsm.setElementName(3, "D");
    dsm.setElementName(4, "E");

    // Add some links
    dsm.addLink("A", "B", 1);
    dsm.addLink("B", "C", 2);
    dsm.addLink("C", "D", 3);
    dsm.addLink("D", "E", 4);

    // Check the link weight
    assert(dsm.linkWeight("A", "B") == 1);
    assert(dsm.linkWeight("B", "C") == 2);
    assert(dsm.linkWeight("C", "D") == 3);
    assert(dsm.linkWeight("D", "E") == 4);

    // Check if a link exists
    assert(dsm.hasLink("A", "B"));
    assert(dsm.hasLink("B", "C"));
    assert(dsm.hasLink("C", "D"));
    assert(dsm.hasLink("D", "E"));
    assert(!dsm.hasLink("A", "C"));
    assert(!dsm.hasLink("B", "D"));
    assert(!dsm.hasLink("C", "E"));

    // Remove a link
    dsm.deleteLink("C", "D");
    assert(!dsm.hasLink("C", "D"));

    // Add some more links
    dsm.addLink("A", "C", 5);
    dsm.addLink("B", "D", 6);
    dsm.addLink("C", "E", 7);

    // Check the link weight
    assert(dsm.linkWeight("A", "B") == 1);
    assert(dsm.linkWeight("B", "C") == 2);
    assert(dsm.linkWeight("A", "C") == 5);
    assert(dsm.linkWeight("B", "D") == 6);
    assert(dsm.linkWeight("C", "E") == 7);
    assert(dsm.linkWeight("D", "E") == 4);

    // Check the total number of links
    assert(dsm.countAllLinks() == 6);

    /*
    for (int i = 0; i < dsm.elementCount; i++) {
        for (int j = 0; j < dsm.elementCount; j++) {
            cout << dsm.elementNames[i] << ":" << dsm.elementNames[j] << " " << dsm.matrix[i][j] << " ";
        }
        cout << "\n";
    }
    */

    // Check the number of links from an element
    assert(dsm.countFromLinks("A") == 2);
    assert(dsm.countFromLinks("B") == 2);
    assert(dsm.countFromLinks("C") == 1);
    assert(dsm.countFromLinks("D") == 1);
    assert(dsm.countFromLinks("E") == 0);

    // Check the number of links to an element
    assert(dsm.countToLinks("A") == 0);
    assert(dsm.countToLinks("B") == 1);
    assert(dsm.countToLinks("C") == 2);
    assert(dsm.countToLinks("D") == 1);
    assert(dsm.countToLinks("E") == 2);

    // Check if an element exists
    assert(dsm.hasElement("A"));
    assert(dsm.hasElement("B"));
    assert(dsm.hasElement("C"));
    assert(dsm.hasElement("D"));
    assert(dsm.hasElement("E"));
    assert(!dsm.hasElement("F"));
}
