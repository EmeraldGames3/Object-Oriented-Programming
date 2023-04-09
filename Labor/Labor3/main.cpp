#include "DependancyStructuredMatrix.h"
#include "TestMatrix.h"

int main() {
    //Initialise four DSMs of different types
    DSM<int> test1(3);
    DSM<float> test2(3);
    DSM<double> test3(3);
    DSM<bool> test4(3);

    //Test the DSM functionalities
    testConstructors();
    test_getName();
    testSetElementName();
    testResizeElementNames();
    testResizeMatrix();
    testGetIndex();
    testAutomaticResize();
    testAddLink1();
    testAddLink2();
    testDSM();

    //TODO Make the pds and use the DSM described in it

    return 0;
}
