#include <iostream>

/**
 * This function uses Euclid's Algorithm to find the greatest common divisor of two natural numbers
*/
int ggT(int x, int y) {

    while (x != y) {
        if (x > y)
            x -= y;
        else
            y -= x;
    }

    return x;
}

/**
 * This function returns true if the two numbers are relative prime to one another
 * or false if they are not relative prime
*/
bool isRelativePrime(int x, int y) {
    if (ggT(x, y) == 1)
        return true;

    return false;
}

/**
 * This function uses the isRelativePrime function to find all numbers that are relative prime to
 * the given number n and print them on the screen
*/
void printAllRelativePrimes(int n) {
    //This is exercise a
    std::cout << "All numbers that are relative prime to " << n << " and are smaller than " << n << " are: ";

    //Check if n is odd
    if (n % 2 != 0)
        std::cout << "2 ";

    for (int i = 3; i < n; i += 2) {
        if (isRelativePrime(i, n)) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
}

/**
 * This function returns the subarray with the maximum sum and changes the parameter len from the length
 * of the original array to the length of the subarray
 *
 * After this function is called the programmer is responsible for freeing the memory occupied by the returned array
**/
int *findSubarrayWithLongestSum(const int numbers[], int &len) {

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

    std::cout << "Enter a number ";
    std::cin >> n;

    printAllRelativePrimes(n);

//    int numbers[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//    int len = sizeof(numbers) / sizeof(numbers[0]);

    int len;
    int *numbers;

    //read numbers from the keyboard
    std::cout << "Enter the length of the array ";
    std::cin >> len;

    numbers = new int[len];

    std::cout << "Now enter the contents of the array" << std::endl;
    for (int i = 0; i < len; i++)
        std::cin >> numbers[i];

    int *maxSubarray = findSubarrayWithLongestSum(numbers, len);

    std::cout << "Maximum subarray: ";
    for (int i = 0; i < len; i++) {
        std::cout << maxSubarray[i] << " ";
    }
    std::cout << std::endl;

    delete[] maxSubarray;

    return 0;
}