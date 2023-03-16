#pragma once

class BankAccount {
private:
    float money;

    void writeToFile(char transactionType, float kosten) const;

public:
    void readFromFile();

    BankAccount();

    explicit BankAccount(float money);

    void auszahlen(float kosten);

    void einzahlen(float kosten);

    [[nodiscard]] float kostenzustan() const;
};