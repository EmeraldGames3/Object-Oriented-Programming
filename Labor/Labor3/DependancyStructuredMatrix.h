#pragma once
#include <string>

using std::string;

template<typename Type>
class DSM {
private:
    Type **matrix;
    string *elementNames;
    int elementCount;

public:
    explicit DSM(int elementCount);

    DSM(string *elementNames, int _elementCount);

    DSM(const DSM &other);

    ~DSM();

    int size();

    string getName(int index);

    void setElementName(int index, string elementName);

    void addLink(string fromElement, string toElement, Type weight);

    void deleteLink(string fromElement, string toElement);

    bool hasLink(string fromElement, string toElement);

    int linkWeight(string fromElement, string toElement);

    int countToLinks(string elementName);

    int countFromLinks(string elementName);

    int countAllLinks();
};