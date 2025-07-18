#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platforms = 0;
        int maxPlatforms = 0;
        int i = 0, j = 0;
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                maxPlatforms = max(maxPlatforms, platforms);
                i++;
            }
            else {
                platforms--;
                j++;
            }
        }
        
        return maxPlatforms;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep1 = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Test 1: " << sol.findPlatform(arr1, dep1) << endl;
    
    vector<int> arr2 = {900, 1235, 1100};
    vector<int> dep2 = {1000, 1240, 1200};
    cout << "Test 2: " << sol.findPlatform(arr2, dep2) << endl;
    
    vector<int> arr3 = {1000, 935, 1100};
    vector<int> dep3 = {1200, 1240, 1130};
    cout << "Test 3: " << sol.findPlatform(arr3, dep3) << endl;
    
    return 0;
}