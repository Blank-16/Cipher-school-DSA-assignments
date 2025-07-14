
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<unordered_map<char, int>> func(string str){
    vector<char> chArr; 

    for(char ch: str) {
        chArr.push_back(ch);
    }    

    unordered_map<char, int> freqMap;
    for (char ch : chArr) {
        freqMap[ch]++;
    }

    vector<unordered_map<char, int>> result;
    result.push_back(freqMap);
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    vector<unordered_map<char, int>> freqVec = func(input);

    cout << "Character frequencies:\n";
    for (const auto& freqMap : freqVec) {
        for (const auto& pair : freqMap) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }

    return 0;
}
