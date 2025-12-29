/*
Platform: LeetCode
Problem: 72 - Find Pivot Index
Approach: Prefix Sum / Running Sum
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0); // Total sum of array
        int left = 0;  // Sum of elements to the left of current index
        
        for (int i = 0; i < n; i++) {
            if (left == total - left - nums[i]) return i; // Check pivot condition
            left += nums[i];
        }

        return -1; // No pivot index found
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << "Pivot Index: " << sol.pivotIndex(nums) << endl;
    return 0;
}
