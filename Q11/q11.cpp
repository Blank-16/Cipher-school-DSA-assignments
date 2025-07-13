
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string isPrime(int n)
{
    vector<int> a;
    int root = sqrt(n);
    while(root < 0)
    {
        if( n % root == 0){
            a.push_back(root);
            root--;
        }
        else {
            root--;
        }
    }

    return a.size() > 2 ? "False" : "True";
}

int factorial(int n)
{
    int fact = 1;
    int temp = n;
    while (temp > 0)
    {
        fact *= temp;
        temp--;
    }

    return fact;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Is it a prime number: " << isPrime(n);
    cout << endl;
    cout << "Factorial of the number: " << factorial(n);

    return 0;
}