
#include <iostream>
using namespace std;
    
bool posCheck(int n){
    return (n > 0) ? true : false;
}

int main(){
    int n;
    cout << "Give a number: ";
    cin >> n;
    
    if(n == 0){
        cout << "Zero";
    }
    else if(posCheck(n)) {
        cout << "Positive";
    } 
    else
    {
        cout << "Negative";
    }
    
    return 0;
}