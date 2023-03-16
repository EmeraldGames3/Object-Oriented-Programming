#include <iostream>
#include "BankAccount.h"

int main() {
    BankAccount bankAccount1 = BankAccount();
    BankAccount bankAccount2(27);

    // Print initial balances
    std::cout << "Account 1 balance: " << bankAccount1.kostenzustan() << std::endl;
    std::cout << "Account 2 balance: " << bankAccount2.kostenzustan() << std::endl;

    // Perform transactions
    bankAccount1.einzahlen(32);
    bankAccount2.auszahlen(16);

    // Print updated balances
    std::cout << "Account 1 balance after deposit: " << bankAccount1.kostenzustan() << std::endl;
    std::cout << "Account 2 balance after withdrawal: " << bankAccount2.kostenzustan() << std::endl;

    BankAccount bankAccount3 = BankAccount();
    bankAccount3.readFromFile();

    std::cout << "Account 3 balance: " << bankAccount3.kostenzustan() << std::endl;

    return 0;
}
