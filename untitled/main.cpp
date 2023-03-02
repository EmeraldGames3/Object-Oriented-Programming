#include <iostream>
#include <vector>

bool relativePrime(int x, int y) {
    if (x == 1 or y == 1)
        return false;

    if (x % 2 == 0 and y % 2 == 0)
        return false;

    for (int i = 3; i <= std::min(x, y); i++) {
        if (x % i == 0 and y % i == 0)
            return false;
    }

    return true;
}

void a(int n) {
    for (int i = 1; i < n; i++) {
        if (relativePrime(i, n))
            std::cout << i << ' ';
    }

    std::cout << std::endl;
}


int main() {

    a(9);

    int x[] = {1, 2, -4, 3, 4, -5, 6, 7, 8, 1, 1, 0, -1, -8};


    int length = 10;
    int* bReturnArray = b(x, length);

    for(int i = 0; i < length; i ++)
        std::cout << bReturnArray[i] << ' ';
    return 0;
}