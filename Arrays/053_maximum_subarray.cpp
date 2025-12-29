/*
Platform: LeetCode
Problem: 53 - Maximum Subarray
Approach: Kadane's Algorithm (Dynamic Programming)
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN; // Maximum sum found so far
        int currSum = 0;      // Current subarray sum
        
        for (int i = 0; i < nums.size(); i++) { 
            currSum += nums[i];
            if (currSum > maxSum) {
                maxSum = currSum; // Update maximum if current sum is greater
            }
            if (currSum < 0) {
                currSum = 0; // Reset current sum if it becomes negative
            }
        }
        
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Maximum Subarray Sum: " << sol.maxSubArray(nums) << endl;
    return 0;
}
