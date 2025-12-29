/*
Platform: LeetCode
Problem: 169 - Majority Element
Approach: Boyer-Moore Voting Algorithm
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;  // Counter for current candidate
        int candidate;  // Potential majority element

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;  // The majority element
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}
