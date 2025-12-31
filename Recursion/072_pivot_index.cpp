/*
Platform: LeetCode
Problem: 72 - Pivot Index
Approach: Prefix Sum
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0); // total sum
        int left = 0;

        for (int i = 0; i < n; i++) {
            if (left == total - left - nums[i]) return i; // pivot found
            left += nums[i];
        }

        return -1; // no pivot
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    cout << "Pivot Index: " << sol.pivotIndex(nums) << endl;
    return 0;
}
