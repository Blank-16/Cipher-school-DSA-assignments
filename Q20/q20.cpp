
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            int comp = target - nums[i];
            if (hash.find(comp) != hash.end())
            {
                return {hash[comp], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }

    bool isSorted(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (i > 0 && arr[i] > arr[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        cout << "No two sum solution found." << endl;
    }

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {5, 4, 3, 2, 1};

    cout << "arr1 is sorted: " << (sol.isSorted(arr1) ? "true" : "false") << endl;
    cout << "arr2 is sorted: " << (sol.isSorted(arr2) ? "true" : "false") << endl;

    return 0;
}
