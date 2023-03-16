#include "BankAccount.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

void BankAccount::auszahlen(float kosten) {
    if (money < kosten) throw std::exception();
    money -= kosten;

    writeToFile('o', kosten);
}

void BankAccount::einzahlen(float kosten) {
    money += kosten;
    writeToFile('i', kosten);
}

float BankAccount::kostenzustan() const {
    return money;
}

BankAccount::BankAccount() {
    money = 0;
}

BankAccount::BankAccount(float money) {
    this->money = money;
}

void BankAccount::writeToFile(char transactionType, float kosten) const {
    std::ofstream outFile("OutputFile.txt", std::ios_base::app);

    if (transactionType == 'i') {
        outFile << "IN " << kosten << ' ' << money << std::endl;
    }
    if (transactionType == 'o') {
        outFile << "OUT " << kosten << ' ' << money << std::endl;
    }

    outFile.close();
}

void BankAccount::readFromFile() {
    std::ifstream inFile("InputFile.txt");

    std::string line;
    while (std::getline(inFile, line)) {
        if(line[0] == 'I'){
            line = line.substr(3);
//            std::cout << line << std::endl;

            std::string temp = "";
            int i = 0;

            while ((line[i]) != ' '){
                temp += line[i];
                i++;
            }
            einzahlen(std::stof(temp));
        }
        if(line[0] == 'O'){
            line = line.substr(4);
//            std::cout << line << std::endl;

            std::string temp = "";
            int i = 0;
            while ((line[i]) != ' '){
                temp += line[i];
                i++;
            }
            auszahlen(std::stof(temp));
        }
    }

    inFile.close();
}

