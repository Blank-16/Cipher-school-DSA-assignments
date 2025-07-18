#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int activitySelection(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    if (n == 0) return 0;
    
    vector<pair<int, int>> activities;
    
    for (int i = 0; i < n; i++) {
        activities.push_back({finish[i], start[i]});
    }
    
    sort(activities.begin(), activities.end());
    
    int count = 1; 
    int lastFinish = activities[0].first;
    
    for (int i = 1; i < n; i++) {
        if (activities[i].second >= lastFinish) {
            count++;
            lastFinish = activities[i].first;
        }
    }
    
    return count;
}


int main() {
    vector<int> start1 = {1, 3, 0, 5, 8, 5};
    vector<int> finish1 = {2, 4, 6, 7, 9, 9};
    cout << activitySelection(start1, finish1) << endl; 

    vector<int> start2 = {10, 12, 20};
    vector<int> finish2 = {20, 25, 30};
    cout << activitySelection(start2, finish2) << endl; 

    vector<int> start3 = {1, 3, 2, 5};
    vector<int> finish3 = {2, 4, 3, 6};
    cout << activitySelection(start3, finish3) << endl; 

    return 0;
}