#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

class BankAccount
{
private:
    string accountNumber;
    double balance;
    vector<string> transactionLog;

    string formatMoney(double amount)
    {
        char buffer[50];
        sprintf(buffer, "%.2f", amount);
        return string(buffer);
    }

public:
    BankAccount(string accNum, double initialBalance)
    {
        accountNumber = accNum;
        balance = initialBalance;
        transactionLog.push_back("Account created with balance: $" + formatMoney(initialBalance));
    }

    ~BankAccount()
    {
        cout << fixed << setprecision(2);
        cout << "Transaction Log for Account " << accountNumber << ":" << endl;
        for (const string &transaction : transactionLog)
        {
            cout << transaction << endl;
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            transactionLog.push_back("Deposited: $" + formatMoney(amount) + " | Balance: $" + formatMoney(balance));
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            transactionLog.push_back("Withdrew: $" + formatMoney(amount) + " | Balance: $" + formatMoney(balance));
        }
        else
        {
            transactionLog.push_back("Failed withdrawal attempt: $" + formatMoney(amount));
        }
    }

    double checkBalance()
    {
        transactionLog.push_back("Balance checked: $" + formatMoney(balance));
        return balance;
    }
};

int main()
{
    BankAccount account("Blank", 99450);

    account.deposit(8929);
    account.withdraw(5044);
    account.checkBalance();
    account.withdraw(9900);

    return 0;
}