#pragma once
#include <string>
#include <stdexcept>

using std::string;

// Type can only be bool, int, float or double
template<typename Type>
class DSM {
private:
    int elementCount;
    int capacity; // Capacity is used to avoid frequent resizing
    Type **matrix;
    string *elementNames;

public:
    //Resize the elementNames array
    void resizeElementNames(int newCapacity);

    //Resize the matrix
    void resizeMatrix(int newCapacity);

    //Automatically resize the elementNames array and the matrix
    void automaticResize();

    //get the index of an element in elementNames
    int getIndex(const string &str);

    //Default constructor with implicit parameters
    explicit DSM(int _elementCount = 0);

    //Constructor with two parameters
    DSM(string *_elementNames, int _elementCount);

    //Copy constructor
    DSM(const DSM<Type> &other);

    //Destructor
    ~DSM();

    //Get the size of the matrix
    int size();

    //Get the capacity of the DSM
    int getCapacity();

    //Get the name of an element
    string getName(int index);

    //Set the name of an element
    void setElementName(int index, const string& elementName);

    //Add a link between two Elements
    void addLink(const string& fromElement, const string& toElement, Type weight);

    //Delete a link between two elements
    void deleteLink(const string& fromElement, const string& toElement);

    //Check if two elements have a link
    bool hasLink(const string& fromElement, const string& toElement);

    //Return the weight of the Link
    Type linkWeight(const string& fromElement, const string& toElement);

    //Check if an element exists in the DSM
    bool hasElement(const string& element);

    int countToLinks(string elementName);

    int countFromLinks(string elementName);

    int countAllLinks();
};