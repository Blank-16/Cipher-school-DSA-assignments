#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> data;
public:
    void push(int value) {
        data.push_back(value);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        } else {
            cerr << "Stack underflow\n";
        }
    }

    int peek() const {
        if (!data.empty()) {
            return data.back();
        } else {
            cerr << "Stack is empty\n";
            return -1; 
        }
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;

    s.pop();
    s.pop();

    if (s.isEmpty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }

    return 0;
}