/*
Platform: LeetCode
Problem: 26 - Remove Duplicates from Sorted Array
Approach: Two Pointers (In-place)
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int j = 1;  // Pointer for the next unique element
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];  // Move unique element forward
                j++;
            }
        }

        return j;  // New length of array without duplicates
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int newLength = sol.removeDuplicates(nums);

    cout << "Length: " << newLength << endl;
    cout << "Array: ";
    for (int i = 0; i < newLength; i++) cout << nums[i] << " ";
    return 0;
}
