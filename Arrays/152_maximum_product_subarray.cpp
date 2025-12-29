/*
Platform: LeetCode
Problem: 152 - Maximum Product Subarray
Approach: Dynamic Programming (Tracking max & min products)
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];  // Maximum product ending at current index
        int minProd = nums[0];  // Minimum product ending at current index
        int ans = nums[0];      // Overall maximum product

        for (int i = 1; i < n; i++) {
            // Swap max and min if current number is negative
            if (nums[i] < 0) swap(maxProd, minProd);

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            ans = max(ans, maxProd);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum Product Subarray: " << sol.maxProduct(nums) << endl;
    return 0;
}
