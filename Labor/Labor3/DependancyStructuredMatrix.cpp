#include <iostream>
#include "DependancyStructuredMatrix.h"

/**
 * @brief Default constructor of templated class DSM
 * @details Allocate memory for an n*n matrix and its corresponding adjacency list
 * @throws invalid_argument if element count is negative
 */
template<typename Type>
DSM<Type>::DSM(int _elementCount) : elementCount(_elementCount), capacity(elementCount * 2 + 1) {
    if (_elementCount < 0)
        throw std::invalid_argument("Element count cannot be negative");

    //Allocate space for the n*n matrix
    matrix = new Type *[capacity];
    for (int i = 0; i < capacity; i++) {
        matrix[i] = new Type[capacity];
        //Initialize the matrix with no links
        for (int j = 0; j < capacity; j++) {
            matrix[i][j] = 0;
        }
    }

    //Allocate space for the elementNames array
    elementNames = new string[capacity];
}

/**
 * @brief Constructor with two parameters of templated class DSM
 * @details Allocate memory for an n*n matrix and fill its corresponding adjacency list
 * @throws invalid_argument if element count is negative
 */
template<typename Type>
DSM<Type>::DSM(string *_elementNames, int _elementCount) : elementCount{_elementCount}, capacity(elementCount * 2 + 1) {
    if (elementCount < 0)
        throw std::invalid_argument("Element count cannot be negative");

    //Allocate space for the n*n matrix
    matrix = new Type *[capacity];
    for (int i = 0; i < capacity; i++) {
        matrix[i] = new Type[capacity];
        //Initialize the matrix with no links
        for (int j = 0; j < capacity; j++) {
            matrix[i][j] = 0;
        }
    }

    //Allocate space for the elementNames array
    elementNames = new string[capacity];

    //Fill the elementNames Array
    for (int i = 0; i < elementCount; i++) {
        elementNames[i] = _elementNames[i];
    }
}

/**
 * @brief Copy constructor of templated class DSM
 */
template<typename Type>
DSM<Type>::DSM(const DSM<Type> &other) : elementCount{other.elementCount}, capacity{other.capacity} {
    //Allocate space for the n*n matrix
    matrix = new Type *[capacity];
    for (int i = 0; i < capacity; i++) {
        matrix[i] = new Type[capacity];
    }

    //Allocate space for the elementNames array
    elementNames = new string[capacity];

    //Copy matrix and elementNames
    for (int i = 0; i < elementCount; i++) {
        elementNames[i] = other.elementNames[i];
        for (int j = 0; j < elementCount; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

/**
 * @brief Templated class DSM destructor
 * @details Free the dynamically allocated memory
 */
template<typename Type>
DSM<Type>::~DSM() {
    //Deallocate matrix
    for (int i = 0; i < elementCount; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    //Deallocate elementNames
    delete[] elementNames;
}

/**
 * Resize the matrix array to a new capacity
 * @throws out_of_range if newCapacity < elementCount
 */
template<typename Type>
void DSM<Type>::resizeMatrix(int newCapacity) {
    if (newCapacity < elementCount)
        throw std::out_of_range("Index out of range");

    auto *newMatrix = new Type *[newCapacity];
    for (int i = 0; i < newCapacity; i++) {
        newMatrix[i] = new Type[newCapacity];
        for (int j = 0; j < newCapacity; j++) {
            if (i < elementCount && j < elementCount) {
                newMatrix[i][j] = matrix[i][j];
            } else {
                newMatrix[i][j] = 0;
            }
        }
    }

    //Deallocate matrix
    for (int i = 0; i < elementCount; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = newMatrix;
    capacity = newCapacity;
}

/**
 * Resize the elementNames array to a new capacity
 * @throws out_of_range if newCapacity < elementCount
 */
template<typename Type>
void DSM<Type>::resizeElementNames(int newCapacity) {
    if (newCapacity < elementCount)
        throw std::out_of_range("Index out of range");

    auto *newArray = new string[newCapacity];
    for (int i = 0; i < elementCount; i++)
        newArray[i] = elementNames[i];

    delete[] elementNames;
    elementNames = newArray;
    capacity = newCapacity;
}

/**
 * @brief automatically resize the matrix and elementNames arrays
 * @details Double the capacity if it reach elementCount is equal to the capacity
 *          Halve the capacity if the array is 3/4 empty
 */
template<typename Type>
void DSM<Type>::automaticResize() {
    if (elementCount >= capacity) {
        resizeElementNames(capacity * 2);
        resizeMatrix(capacity * 2);
    } else if (elementCount <= capacity / 4 && capacity >= 10) {
        resizeElementNames(capacity / 2);
        resizeMatrix(capacity / 2);
    }
}

/**
 * @brief Get the index of an element in elementNames
 * @details This index represents a row/column in the matrix
 */
template<typename Type>
int DSM<Type>::getIndex(const string &str) {
    for (int i = 0; i < elementCount; i++)
        if (elementNames[i] == str)
            return i;
    return -1;  // element not found in DSM
}

/**
 * @return The size of the matrix
 * @details The size of the matrix is element count(The size of rows and columns)
 */
template<typename Type>
int DSM<Type>::size() {
    return elementCount;
}

/**
 * @return The capacity of the DSM
 */
template<typename Type>
int DSM<Type>::getCapacity() {
    return capacity;
}

/**
 * @return The element at the provided index
 * @throws invalid_argument if the index is invalid
 */
template<typename Type>
string DSM<Type>::getName(int index) {
    if (index < 0 || index >= elementCount)
        throw std::invalid_argument("Invalid index");
    return string(elementNames[index]); // ensure that we don't return a reference, but a copy
}

/**
 * @brief Set the name of an element at a specific index
 * @throws invalid_argument if the index is invalid
 */
template<typename Type>
void DSM<Type>::setElementName(int index, const string &elementName) {
    if (index < 0 || index >= elementCount)
        throw std::invalid_argument("Invalid index");
    elementNames[index] = elementName;
}

/**
 * @brief Add a new element
 * @details If the element already exist return its index
 */
template<typename Type>
int DSM<Type>::addElementName(string element) {
    int index = getIndex(element);

    // If element exists return it's index
    if (index != -1)
        return index;

    elementNames[elementCount] = element;
    elementCount++;
    automaticResize();
    return elementCount - 1;
}

/**
 * @brief Add a link between two elements if they exist in the DSM or add the elements if they are not in the DSM
 * @details The column is from where the relation comes, and the row is where it goes
 */
template<typename Type>
void DSM<Type>::addLink(string fromElement, string toElement, Type weight) {
    // Check if fromElement and toElement is the DSM
    //If they are not add them
    int fromIndex = getIndex(fromElement);
    int toIndex = getIndex(toElement);

    if(fromIndex == -1){
        elementNames[elementCount] = fromElement;
        fromIndex = elementCount;
        elementCount++;
        automaticResize();
    }

    if(toIndex == -1){
        elementNames[elementCount] = toElement;
        toIndex = elementCount;
        elementCount++;
        automaticResize();
    }

    matrix[fromIndex][toIndex] = weight;
}

/**
 * @brief Delete the link between two Elements
 * @details 0 in the matrix means that there is no link
 */
template<typename Type>
void DSM<Type>::deleteLink(const string &fromElement, const string &toElement) {
    matrix[getIndex(fromElement)][getIndex(toElement)] = 0;
}

/**
 * @brief Check if there is a link between two elements
 * @details 0 in the matrix means that there is no link
 */
template<typename Type>
bool DSM<Type>::hasLink(const string &fromElement, const string &toElement) {
    return matrix[getIndex(fromElement)][getIndex(toElement)] != 0;
}

/**
 * @brief Get the weight of a link between two elements
 * @details 0 in the matrix means that there is no link
 */
template<typename Type>
Type DSM<Type>::linkWeight(const string &fromElement, const string &toElement) {
    return matrix[getIndex(fromElement)][getIndex(toElement)];
}

/**
 * @brief Check if an element exists in the DSM
 */
template<typename Type>
bool DSM<Type>::hasElement(const string &element) {
    return getIndex(element) != -1;
}

/**
 * @brief Remove an element from the DSM
 * @return True if the element was found and removed, false otherwise
 */
template<typename Type>
bool DSM<Type>::removeElement(const string &elementName) {
    // Find the index of the element to remove
    int index = getIndex(elementName);
    if (index == -1) {
        // The element was not found
        return false;
    }

    // Remove the element from the element names array
    for (int i = index; i < elementCount - 1; i++) {
        elementNames[i] = elementNames[i + 1];
    }
    elementNames[elementCount - 1] = "";
    elementCount--;

    // Remove the element's row from the matrix
    for (int i = 0; i < elementCount; i++) {
        for (int j = index; j < elementCount - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }
        matrix[i][elementCount - 1] = Type();
    }

    // Resize the matrix and element names arrays if necessary
    automaticResize();

    return true;
}

/**
 * @brief Count the total amount of links in the DSM
 */
template<typename Type>
int DSM<Type>::countAllLinks() {
    int totalLinks = 0;
    for (int i = 0; i < elementCount; i++) {
        for (int j = 0; j < elementCount; j++) {
            if (matrix[i][j] != 0) {
                totalLinks++;
            }
        }
    }
    return totalLinks;
}

/**
 * @brief Count all the links from an element to all other elements
 */
template<typename Type>
int DSM<Type>::countFromLinks(string elementName) {
    int fromLinks = 0;
    int index = getIndex(elementName);
    if (index == -1) {
        throw std::invalid_argument("Element not found in DSM");
    }
    for (int i = 0; i < elementCount; i++) {
        if (matrix[index][i] != 0) {
            fromLinks++;
        }
    }
    return fromLinks;
}

/**
 * @brief Count the total amount of links to an element from all other elements
 */
template<typename Type>
int DSM<Type>::countToLinks(string elementName) {
    int toLinks = 0;
    int index = getIndex(elementName);
    if (index == -1) {
        throw std::invalid_argument("Element not found in DSM");
    }
    for (int i = 0; i < elementCount; i++) {
        if (matrix[i][index] != 0) {
            toLinks++;
        }
    }
    return toLinks;
}

//Instantiate the templated class to allow the compiler to generate the necessary code
template class DSM<bool>;
template class DSM<int>;
template class DSM<float>;
template class DSM<double>;