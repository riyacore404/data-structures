/*
Platform: LeetCode
Problem: 75 - Sort Colors
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
    void sortColors(vector<int>& nums) {
        // Dutch National Flag problem
        int l = 0, m = 0, h = nums.size() - 1;
        
        //we basically divide the array into three parts l(0), h(2) and m(1)
        //the core idea is to compare the curr val of m with l & h and swap it along the way if its not one
        while(m <= h){
            if (nums[m] == 0){
                swap(nums[m], nums[l]);
                l++;
                m++; //we can safely move m because we've already iterated over the indices before it
            }
            else if (nums[m] == 1){
                m++;
            }
            else {
                swap(nums[m], nums[h]);
                h--;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sol.sortColors(nums);

    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}