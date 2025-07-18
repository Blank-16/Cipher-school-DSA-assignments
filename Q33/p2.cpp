#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        m[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& p : m) {
        result.push_back(move(p.second));
    }
    return result;
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> grouped = groupAnagrams(strs);

    for (const auto& group : grouped) {
        cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << "\"" << group[i] << "\"";
            if (i != group.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}