#include <iostream>
#include <vector>
using namespace std;

class Queue {
    vector<int> arr;
    int front = 0;
public:
    void enqueue(int value) {
        arr.push_back(value);
    }
    void dequeue() {
        if (!isEmpty()) {
            front++;
            if (front > arr.size() / 2) {
                arr.erase(arr.begin(), arr.begin() + front);
                front = 0;
            }
        }
    }
    int peek() {
        if (!isEmpty())
            return arr[front];
        throw out_of_range("Queue is empty");
    }
    bool isEmpty() {
        return front >= arr.size();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.peek() << endl;
    q.dequeue();
    cout << "Front after dequeue: " << q.peek() << endl;
    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    q.dequeue();
    q.dequeue();
    cout << "Is empty after removing all? " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}