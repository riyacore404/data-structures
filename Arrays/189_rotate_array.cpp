/*
Platform: LeetCode
Problem: 189 - Rotate Array
Approach: In-place Rotation using Index Mapping (Swap)
Time Complexity: O(n)
Space Complexity: O(1) extra (though your current code uses a temp vector, ideally O(1) in-place)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle cases where k >= n

        // Rotate elements using swap (index mapping)
        for (int i = 0; i < n; i++) {
            swap(nums[(i + k) % n], nums[i]);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    sol.rotate(nums, k);

    for (int num : nums) cout << num << " ";
    return 0;
}
