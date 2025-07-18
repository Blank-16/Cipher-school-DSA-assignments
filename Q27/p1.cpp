#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(const string& s) {
    unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (count[s[i]] == 1) return i;
    }
    return -1;
}

int main() {
    string s;
    cin >> s;
    cout << firstUniqChar(s) << endl;
    return 0;
}