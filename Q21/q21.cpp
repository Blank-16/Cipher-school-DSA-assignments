#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {

    int n = arr.size();
    cout << "Selection Sort Progress:\n";

    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        cout << "Iteration " << i << ": selected index " << minIdx << " (value " << arr[minIdx] << ")\n";
        swap(arr[i], arr[minIdx]);
    }
}

int insertionSort(vector<int>& arr) {
    int n = arr.size();
    int shifts = 0;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
            ++shifts;
        }

        arr[j + 1] = key;
        if (j + 1 != i) ++shifts; 
    }
    return shifts;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr1 = {64, 25, 12, 22, 11};
    vector<int> arr2 = arr1;
    vector<int> arr3 = arr1;

    selectionSort(arr1);
    cout << "Sorted array (Selection Sort): ";
    printArray(arr1);

    int shifts = insertionSort(arr2);
    cout << "Sorted array (Insertion Sort): ";
    printArray(arr2);
    cout << "Total shifts/swaps in Insertion Sort: " << shifts << endl;

    bubbleSort(arr3);
    cout << "Sorted array (Bubble Sort): ";
    printArray(arr3);

    return 0;
}