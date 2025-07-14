
#include <iostream>
using namespace std;

void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void modifyByValue(int x) {
    cout << "Inside modifyByValue, address: " << &x << endl;
    x = x + 1;
}

void modifyByReference(int& x) {
    cout << "Inside modifyByReference, address: " << &x << endl;
    x = x + 1;
}

int main() {
    int num1 = 5, num2 = 10;
    cout << "Before swap: " << num1 << ", " << num2 << endl;
    swapByReference(num1, num2);
    cout << "After swap: " << num1 << ", " << num2 << endl;

    int x = 100;
    cout << "\nOriginal x address: " << &x << ", value: " << x << endl;
    
    modifyByValue(x);
    cout << "After pass by value: " << x << endl;
    
    modifyByReference(x);
    cout << "After pass by reference: " << x << endl;

    return 0;
}