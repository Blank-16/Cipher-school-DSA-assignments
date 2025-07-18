#include <iostream>
#include <stack>
#include <limits>

using namespace std;

class MinStack {
    stack<int> s;
    stack<int> minS;
public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        if (minS.empty() || val <= minS.top()) {
            minS.push(val);
        } else {
            minS.push(minS.top());
        }
    }

    void pop() {
        s.pop();
        minS.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};


int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;    
    cout << minStack.getMin() << endl; 
    return 0;
}