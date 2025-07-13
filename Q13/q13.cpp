#include <iostream>
#include <vector>
using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    vector<int> allPrimeInNumber = sieveOfEratosthenes(n);
    
    for (int prime : allPrimeInNumber) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
