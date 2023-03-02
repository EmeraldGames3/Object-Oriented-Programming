#include <iostream>

using namespace std;

bool relativePrime(int x, int y) {
    if (x % 2 == 0 and y % 2 == 0)
        return false;

    for(int i = 0; i <= min(x, y); i ++){
        if(x % i == 0 and y % i == 0)
            return false;
    }

    return true;
}

int main() {

    if (relativePrime(3, 4))
        cout<<"Da"<<endl;
    cout << relativePrime(2, 4)<< endl;
    cout << relativePrime(3, 5)<< endl;

    return 0;
}
