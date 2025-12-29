/*
Platform: LeetCode
Problem: 349 - Intersection of Two Arrays
Approach: Hash Map / Frequency Marking
Time Complexity: O(n + m)  // n = size of nums1, m = size of nums2
Space Complexity: O(n)     // For storing elements of nums1 in hash map
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        
        for (int i : nums1) mpp[i] = 1; // Mark all elements of nums1

        vector<int> inter;
        for (int i : nums2) {
            if (mpp[i]) {          // If element is in nums1 and not yet added
                inter.push_back(i);
                mpp[i] = 0;        // Mark as added to avoid duplicates
            }
        }

        return inter;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    vector<int> res = sol.intersection(nums1, nums2);
    cout << "Intersection: ";
    for (int num : res) cout << num << " ";
    return 0;
}
