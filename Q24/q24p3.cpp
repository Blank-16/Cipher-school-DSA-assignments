#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> jobScheduling(vector<int>& deadlines, vector<int>& profits) {
    int n = deadlines.size();

    vector<pair<int, int>> jobs(n);
    for(int i = 0; i < n; i++) {
        jobs[i] = {profits[i], deadlines[i]};
    }

    sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

    int maxDeadline = *max_element(deadlines.begin(), deadlines.end());
    vector<int> parent(maxDeadline + 1);
    for(int i = 0; i <= maxDeadline; i++) parent[i] = i;

    function<int(int)> find = [&](int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    };

    int jobCount = 0, totalProfit = 0;
    for(int i = 0; i < n; i++) {
        int d = jobs[i].second;
        int available = find(d);
        if(available > 0) {
            parent[available] = find(available - 1);
            jobCount++;
            totalProfit += jobs[i].first;
        }
    }
    return {jobCount, totalProfit};
}

int main() {
    vector<vector<int>> deadlines = {
        {4, 1, 1, 1},
        {2, 1, 2, 1, 1},
        {3, 1, 2, 2}
    };
    
    vector<vector<int>> profits = {
        {20, 10, 40, 30},
        {100, 19, 27, 25, 15},
        {50, 10, 20, 30}
    };
    
    for(int i = 0; i < deadlines.size(); i++) {
        vector<int> result = jobScheduling(deadlines[i], profits[i]);
        cout << "Test case " << i + 1 << ": [" << result[0] << ", " << result[1] << "]" << endl;
    }
    
    return 0;
}
