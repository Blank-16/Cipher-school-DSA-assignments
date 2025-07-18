#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isIsomorphic(const string& s, const string& t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, char> map_s_t, map_t_s;
    for (size_t i = 0; i < s.length(); ++i) {
        char cs = s[i], ct = t[i];
        if ((map_s_t.count(cs) && map_s_t[cs] != ct) ||
            (map_t_s.count(ct) && map_t_s[ct] != cs)) {
            return false;
        }
        map_s_t[cs] = ct;
        map_t_s[ct] = cs;
    }
    return true;
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;
    cout << (isIsomorphic(s, t) ? "true" : "false") << endl;
    return 0;
}