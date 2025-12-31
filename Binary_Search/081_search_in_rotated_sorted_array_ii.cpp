/*
Platform: LeetCode
Problem: 81 - Search in Rotated Sorted Array II
Approach: Modified Binary Search with Duplicate Handling
Time Complexity: O(log n) average, O(n) worst case
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] == target) return true;

            // Handle duplicates
            if (nums[l] == nums[mid] && nums[mid] == nums[h]) {
                l++;
                h--;
            }
            // Left half is sorted
            else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    cout << (sol.search(nums, target) ? "true" : "false") << endl;
    return 0;
}
