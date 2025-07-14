
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sumArray(vector<int> arr, int n)
{
    int sum = 0;
    for(auto c: arr) 
    {
        sum += c;   
    }
    return sum;
}

pair<int, int> findMaxMin(vector<int> arr)
{
    unordered_map<string, int> result;
    if (arr.empty()) return {0, 0};
    int maxVal = arr[0], minVal = arr[0];
    for (auto num : arr) {
        if (num > maxVal) maxVal = num;
        if (num < minVal) minVal = num;
    }
    result["max"] = maxVal;
    result["min"] = minVal;
    return {result["max"], result["min"]};
}

int main()
{
    vector<int> arr = {5, 8, 2, 9, 1, 7, 3, 6, 4, 0, 11, 13, 12, 10, 14};
    cout << "Sum: " << sumArray(arr, arr.size()) << endl;
    auto [maxVal, minVal] = findMaxMin(arr);
    cout << "Max: " << maxVal ;
    cout << "\nMin: " << minVal << endl;
    return 0;
}