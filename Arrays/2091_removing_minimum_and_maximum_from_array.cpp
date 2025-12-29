/*
Platform: LeetCode
Problem: 2091 - Removing Minimum and Maximum From Array
Approach: Greedy / Index Tracking
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int maxi = INT_MIN, mini = INT_MAX;
        int idxMax = -1, idxMin = -1;

        // Find indices of maximum and minimum elements
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                idxMax = i;
            }
            if (nums[i] < mini) {
                mini = nums[i];
                idxMin = i;
            }
        }

        // Three possible strategies:
        int left = max(idxMax, idxMin) + 1;                          // Remove both from left
        int right = n - min(idxMax, idxMin);                        // Remove both from right
        int both = min(idxMax, idxMin) + 1 + (n - max(idxMax, idxMin)); // Remove one from left, one from right

        return min({left, right, both});
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,10,7,5,4,1,8,6};
    cout << "Minimum Deletions: " << sol.minimumDeletions(nums) << endl;
    return 0;
}