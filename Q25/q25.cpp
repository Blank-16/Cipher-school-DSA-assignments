
#include <iostream>
    
using namespace std;

void recurrNumberPrint(int n)
{
    if (n >= 1) {
        cout << n << " ";
        recurrNumberPrint(n - 1);
    }
}

int trailingZeroes(int n) {
    if (n == 0)
        return 0;
    return n / 5 + trailingZeroes(n / 5);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Numbers from " << n << " to 1: ";
    recurrNumberPrint(n);
    cout << endl;

    cout << "Number of trailing zeroes in " << n << "! is: " << trailingZeroes(n) << endl;

    return 0;

}