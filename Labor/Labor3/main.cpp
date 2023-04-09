#include "DependancyStructuredMatrix.h"
#include "TestMatrix.h"

int main() {
    DSM<int> test1(3);
    DSM<float> test2(3);
    DSM<double> test3(3);
    DSM<bool> test4(3);

    testConstructors();
    test_getName();
    testSetElementName();
    testResizeElementNames();
    testResizeMatrix();
    testGetIndex();
    testAutomaticResize();
    testAddLink1();
    testAddLink2();
    return 0;
}
