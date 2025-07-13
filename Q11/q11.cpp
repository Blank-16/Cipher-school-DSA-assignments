
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string isPrime(int n)
{
    if (n <= 1) return "False";
    if (n == 2) return "True";
    
    vector<int> a;
    int root = sqrt(n);
    for(int i = 2; i <= root; i++)
    {
        if( n % i == 0){
            a.push_back(i);
        }
    }

    return a.size() > 0 ? "False" : "True";
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