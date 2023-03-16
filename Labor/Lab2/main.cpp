#include <iostream>
#include "Length.h"

int main() {
    Length l1 = Length();
    Length l2 = Length(12);
    Length l3 = Length(11.5, "Meters");
    Length l4 = Length(l3);

//    l2.scale(12);
//    l3.divide(2);
    l1 = l1.add(l2);
    l2 = l2.subtract(l1);

    std::cout<<"L1: " << l1.text() << std::endl;
    std::cout<<"L2: " << l2.text() << std::endl;
    std::cout<<"L3: " << l3.text() << std::endl;
    std::cout<<"L4: " << l4.text() << std::endl;

    return 0;
}
