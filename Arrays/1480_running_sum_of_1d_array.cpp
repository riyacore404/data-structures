/*
Platform: LeetCode
Problem: 1480 - Running Sum of 1d Array
Approach: Prefix Sum (In-place)
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1]; // Update current element to include sum of previous elements
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = sol.runningSum(nums);

    cout << "Running Sum: ";
    for (int num : res) cout << num << " ";
}