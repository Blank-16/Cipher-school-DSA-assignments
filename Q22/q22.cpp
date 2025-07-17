#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        { // arr[mid] == 2
            swap(arr[mid], arr[high--]);
        }
    }
}

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(const vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

void binarySearchTracing(const vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1, iterations = 0;
    cout << "Binary search trace for target " << target << ": ";

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        cout << mid << " ";
        ++iterations;

        if (arr[mid] == target)
        {
            cout << "\nFound at index " << mid << " in " << iterations << " iterations." << endl;
            return;
        }

        else if (arr[mid] < target)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    cout << "\nNot found after " << iterations << " iterations." << endl;
}

int main()
{
    vector<int> arr1 = {0, 1, 2, 0, 1, 2};
    vector<int> arr2 = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

    vector<int> b= {12, 45, 23, 99, 8, 34, 56, 77, 3, 18};
    bubbleSort(b);
    cout << "Binary search with tracers: \n";
    binarySearchTracing(b, 99);
    cout << endl;

    sort012(arr1);
    sort012(arr2);
    cout << "Sorted using Dutch National Flag Algorithm:" << endl;
    printArray(arr1);
    printArray(arr2);

    vector<int> arr3 = {0, 1, 2, 0, 1, 2};
    vector<int> arr4 = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    bubbleSort(arr3);
    bubbleSort(arr4);
    cout << "Sorted using Bubble Sort:" << endl;
    printArray(arr3);
    printArray(arr4);

    // Time complexity comparison:
    cout << "\nTime Complexity:" << endl;
    cout << "Dutch National Flag Algorithm: O(n), one pass, constant extra space." << endl;
    cout << "Bubble Sort: O(n^2), multiple passes, constant extra space." << endl;

    return 0;
}