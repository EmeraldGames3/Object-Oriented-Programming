#include <iostream>
#include <vector>

using namespace std;

int ggT(int x, int y) {
    /**
     * This function uses Euclid's Algorithm to find the greatest common divisor of two natural numbers
     */
    while (x != y) {
        if (x > y)
            x -= y;
        else
            y -= x;
    }

    return x;
}

bool isRelativePrime(int x, int y) {
    /**
     * This function uses the ggT function to determine if two numbers are relatively prime
     */
    if (ggT(x, y) == 1)
        return true;

    return false;
}

void a(int n) {
    /**
     * This function uses the isRelativePrime function to find all numbers that are relative prime to
     * the given number n and print them on the screen
     */
    cout << "All numbers that are relative prime to " << n << " and are smaller than " << n << " are: ";

    //Check if n is odd
    if (n % 2 != 0)
        cout << "2 ";

    for (int i = 3; i * i <= n; i += 2) {
        if (isRelativePrime(i, n)) {
            cout << i << ' ';
        }
    }
    cout << endl;
}

int *b(const int numbers[], int &len) {
    /**
     * This function returns the subarray with the maximum sum and changes the parameter len from the length
     * of the original array to the length of the subarray
     **/
    int maxSum = 0;
    int currentSum = 0;
    int startIndex = 0;
    int endIndex = 0;
    int currentStartIndex = 0;

    //Kadane-Algorithm for the subArray with the biggest sum
    for (int i = 0; i < len; i++) {
        currentSum += numbers[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
            startIndex = currentStartIndex;
            endIndex = i;
        }

        if (currentSum < 0) {
            currentSum = 0;
            currentStartIndex = i + 1;
        }
    }

    //Here we declare the array that we will return
    len = endIndex - startIndex + 1;
    int *maxSubarray = new int[len];

    int j = 0;
    //Here we store the subarray with the biggest sum in a variable so that we can return it
    for (int i = startIndex; i <= endIndex; i++) {
        maxSubarray[j] = numbers[i];
        j++;
    }

    return maxSubarray;
}

int main() {
    int n;

    cout << "Enter a number ";
    cin >> n;

    a(n);

    int numbers[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int len = sizeof(numbers) / sizeof(numbers[0]);

    int *maxSubarray = b(numbers, len);

    cout << "Maximum subarray: ";
    for (int i = 0; i < len; i++) {
        cout << maxSubarray[i] << " ";
    }
    cout << std::endl;

    delete[] maxSubarray;

    return 0;
}
