/*
Platform: LeetCode
Problem: 88 - Merge Sorted Array
Approach: Two Pointers
Time Complexity: O(n)
Space Complexity: O(1)
*/

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) nums1 = nums2;
        if (n == 0) return;

        int i = m - 1;  //last element of nums1
        int j = n - 1;  //last element of nums2
        int k = m + n - 1;  //last index of nums1

        // we basically match the maximum elements of nums1 & nums2 in every iteration and update the elements of nums1 from the end
        while (i >= 0 && j >= 0){
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i]; i--;
            }
            else {
                nums1[k] = nums2[j]; j--;
            }
            k--;
        }

        // if m < n then we can just copy the remaining array nums2 into the remaining space in nums1
        while (j >= 0) {
            nums1[k] = nums2[j]; 
            k--,j--;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);

    for (int i : nums1) cout << i << " ";

    return 0;
}