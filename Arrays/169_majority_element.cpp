/*
Platform: LeetCode
Problem: 169 - Majority Element
Approach1: Sorting + Hash Map Counting 
Time Complexity: O(n log n)  // Sorting dominates
Space Complexity: O(n)     // Hash map to store frequencies
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort array
        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;            // Count frequency of each element
        }

        int c = nums[0];               // Candidate for majority element
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for(int j = 1; j < nums.size(); j++){
            if (mpp[nums[j]] > mpp[c]){
                c = nums[j];           // Update candidate with higher frequency
            }
        }
        
        return c;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}
