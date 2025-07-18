#include <iostream>
#include <vector>
using namespace std;

int majorityElement(const vector<int>& arr) {
    int count = 0, candidate = -1;
    for (int num : arr) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (candidate == num) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for (int num : arr) {
        if (num == candidate) count++;
    }
    if (count > arr.size() / 2)
        return candidate;
    return -1;
}

int main() {
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
    cout << majorityElement(arr) << endl;
    return 0;
}