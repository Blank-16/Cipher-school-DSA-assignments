
#include<iostream>
using namespace std;

void swap(int &a , int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main(){
    int a = 12, b = 15;
    swap(a, b);
    cout << a << " " << b;

    return 0;
}