/*
Platform: LeetCode
Problem: 78 - Subsets
Approach: Recursion / Backtracking
Time Complexity: O(2^n * n)  // 2^n subsets, copying subset of size up to n
Space Complexity: O(n)      // Recursive call stack + current subset
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void generateSubsets(vector<int>& nums, int n, vector<int>& curr, vector<vector<int>>& ans) {
        if (n < 0) {
            ans.push_back(curr);
            return;
        }

        // Exclude nums[n]
        generateSubsets(nums, n - 1, curr, ans);

        // Include nums[n]
        curr.push_back(nums[n]);
        generateSubsets(nums, n - 1, curr, ans);
        curr.pop_back(); // backtrack
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        generateSubsets(nums, n - 1, curr, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> res = sol.subsets(nums);

    cout << "All subsets:" << endl;
    for (auto &subset : res) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}
