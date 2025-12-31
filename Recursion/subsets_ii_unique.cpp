/*
Platform: GeeksforGeeks / LeetCode
Problem: Subsets II (Unique Subsets)
Approach: Backtracking with Sorting & Duplicate Skipping
Time Complexity: O(2^n * n)
Space Complexity: O(n)  // Recursive call stack + current subset
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int>> ans;

    void dfs(int idx, vector<int>& arr, vector<int>& subs) {
        ans.push_back(subs);

        int n = arr.size();
        for (int i = idx; i < n; i++) {
            // Skip duplicates
            if (i > idx && arr[i] == arr[i - 1]) continue;

            subs.push_back(arr[i]);
            dfs(i + 1, arr, subs);
            subs.pop_back(); // backtrack
        }
    }

public:
    vector<vector<int>> findSubsets(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // Sort to handle duplicates
        vector<int> subs;
        dfs(0, arr, subs);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 2};

    vector<vector<int>> res = sol.findSubsets(arr);

    cout << "All unique subsets:" << endl;
    for (auto &subset : res) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}
