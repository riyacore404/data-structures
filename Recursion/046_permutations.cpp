/*
Platform: LeetCode
Problem: 46 - Permutations
Approach: Backtracking / Recursion
Time Complexity: O(n! * n)  // n! permutations, copying array of size n
Space Complexity: O(n)      // Recursive call stack
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void backtrack(int idx, vector<vector<int>>& ans, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            backtrack(idx + 1, ans, nums);
            swap(nums[idx], nums[i]); // backtrack
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(0, ans, nums);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> res = sol.permute(nums);

    cout << "All permutations:" << endl;
    for (auto &perm : res) {
        cout << "[ ";
        for (int num : perm) cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}
