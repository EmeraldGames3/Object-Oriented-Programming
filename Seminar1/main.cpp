#include <iostream>

using namespace std;

void ubung1() {
    cout << "Enter your name ";
    string vorname;
    string familyName;
    cin >> vorname;

    cout << "Enter your family name ";
    cin >> familyName;
    cout << endl;

    int bAnzahl = familyName.size() + vorname.size();

    cout << "Hello" << vorname << " " << familyName << " " << bAnzahl << endl;
}

struct Kunde {
    int number;
    string name;
    int postleitzahl;
    string Ortsname;
};

int **multiplyMatrices(int **matrix1, int **matrix2, int n1, int m1, int n2, int m2) {
    if (m1 != n2) {
        return nullptr;
    }

    // Allocate the result matrix on the heap
    int **result = new int *[n1];
    for (int i = 0; i < n1; i++) {
        result[i] = new int[m2];
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}


int main() {
    ubung1();

    Kunde k = {1, "A", 1, "Abc"};
    Kunde k2 = {21, "B", 4, "Abc"};

    Kunde kundeList[] = {k, k2};

    // Define matrix dimensions and values
    int n1 = 3, m1 = 2, n2 = 2, m2 = 4;
    int matrix1_values[] = {1, 2, 3, 4, 5, 6};
    int matrix2_values[] = {7, 8, 9, 10, 11, 12, 13, 14};

    // Allocate memory for matrices
    int **matrix1 = new int*[n1];
    for (int i = 0; i < n1; i++) {
        matrix1[i] = new int[m1];
        for (int j = 0; j < m1; j++) {
            matrix1[i][j] = matrix1_values[i * m1 + j];
        }
    }

    int **matrix2 = new int*[n2];
    for (int i = 0; i < n2; i++) {
        matrix2[i] = new int[m2];
        for (int j = 0; j < m2; j++) {
            matrix2[i][j] = matrix2_values[i * m2 + j];
        }
    }

    // Compute product of matrices
    int **result = multiplyMatrices(matrix1, matrix2, n1, m1, n2, m2);

    // Print input and output matrices
    cout << "First matrix:" << endl;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Second matrix:" << endl;
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Product matrix:" << endl;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}


