
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Bank
{
    string clientName;
    vector<unordered_map<string, int>> transHistory;
    int totalMoney;
    const string transMethod[3] = {"Deposited", "Debited", "Credited"};

public:
    Bank(string name, int amt)
    {
        this->clientName = name;
        if (amt < 0) amt = 0; 
        this->totalMoney = amt;
        unordered_map<string, int> trans;
        trans[transMethod[0]] = amt;
        transHistory.push_back(trans);
    }

    void deposit(int amt)
    {
        if (amt < 0) {
            cout << "Deposit amount must be positive.\n";
            return;
        }
        totalMoney += amt;
        unordered_map<string, int> trans;
        trans[transMethod[0]] = amt;
        transHistory.push_back(trans);
    }

    void debit(int amt)
    {
        if (amt <= 0) {
            cout << "Debit amount must be positive.\n";
            return;
        }
        if (amt > totalMoney) {
            cout << "Insufficient funds for debit.\n";
            return;
        }
        totalMoney -= amt;
        unordered_map<string, int> trans;
        trans[transMethod[1]] = amt;
        transHistory.push_back(trans);
    }
    
    void credit(int amt)
    {
        if (amt <= 0) {
            cout << "Credit amount must be positive.\n";
            return;
        }
        totalMoney += amt;
        unordered_map<string, int> trans;
        trans[transMethod[2]] = amt;
        transHistory.push_back(trans);
    }

    void printData()
    {
        cout << "Client Name:\t" << clientName << endl;
        cout << "Current Balance:\t" << totalMoney << endl;
        cout << "Transaction History:\n";
        cout << "Operation\tAmount\n";
        for (const auto &trans : transHistory) {
            for (const auto &entry : trans) {
                cout << entry.first << "\t" << entry.second << endl;
            }
        }
    }
};

unordered_map<int, int> getFrequency(const vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (int num : arr)
    {
        freq[num]++;
    }
    return freq;
}

int main()
{
    Bank b1("Alice", 1000);
    b1.deposit(500);
    b1.debit(200);
    b1.credit(300);

    Bank b2("Bob", 2000);
    b2.deposit(1000);
    b2.debit(500);
    b2.credit(700);

    Bank b3("Charlie", 1500);
    b3.deposit(200);
    b3.debit(100);
    b3.credit(400);

    b1.printData();
    b2.printData();
    b3.printData();

    return 0;
}