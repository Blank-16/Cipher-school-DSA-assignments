
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int secondLargest(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr.at(arr.size() - 2);
}

int main(){
    vector<int> arr = {45, 23, 78, 12, 56, 89, 34, 67, 91, 28}; 
    cout << "Array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Second largest: " << secondLargest(arr) << endl;
    
    return 0;
}