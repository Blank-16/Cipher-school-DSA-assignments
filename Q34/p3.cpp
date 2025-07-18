#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1, right = *max_element(piles.begin(), piles.end());
    int result = right;
    auto hoursNeeded = [](const vector<int> &piles, int k)
    {
        long long hours = 0;
        for (int pile : piles)
        {
            hours += (static_cast<long long>(pile) + k - 1) / k;
        }
        return hours;
    };
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (hoursNeeded(piles, mid) <= h)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingSpeed(piles, h) << endl; // Output: 4

    piles = {30, 11, 23, 4, 20};
    h = 5;
    cout << minEatingSpeed(piles, h) << endl; // Output: 30

    piles = {30, 11, 23, 4, 20};
    h = 6;
    cout << minEatingSpeed(piles, h) << endl; // Output: 23

    return 0;
}