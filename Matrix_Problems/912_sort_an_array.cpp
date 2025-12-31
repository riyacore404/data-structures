/*
Platform: LeetCode
Problem: 912 - Sort an Array
Approach: Heap Sort
Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && nums[l] > nums[largest])
            largest = l;
        if (r < n && nums[r] > nums[largest])
            largest = r;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }

        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 3, 1};

    vector<int> sorted = sol.sortArray(nums);

    cout << "Sorted array: [ ";
    for (int num : sorted) cout << num << " ";
    cout << "]" << endl;

    return 0;
}
