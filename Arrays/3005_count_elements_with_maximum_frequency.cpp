/*
Platform: LeetCode
Problem: Count Elements With Maximum Frequency
Approach: Hash Map / Frequency Counting
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i : nums) mpp[i]++;  // Count frequency of each element

        int m = INT_MIN, t = 0;
        for (const auto &pair : mpp) {
            if (m < pair.second) {
                m = pair.second;  // Update maximum frequency
                t = m;            // Reset sum to max frequency
            } else if (m == pair.second) {
                t += m;           // Add frequency if it ties with max
            }
        }

        return t;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    cout << sol.maxFrequencyElements(nums) << endl;
    return 0;
}
