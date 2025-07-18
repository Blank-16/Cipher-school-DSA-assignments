#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(const string& s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else {
            if (stk.empty()) return false;
            char top = stk.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << (isValid(s) ? "true" : "false") << endl;
    return 0;
}