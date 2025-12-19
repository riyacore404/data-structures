/*
Platform: LeetCode
Problem: 11 - Container With Most Water
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
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, h = n - 1;
        int maxi = INT_MIN;

        while (l < h) {
            int vol = min(height[h],height[l]) * (h - l);
            maxi = max(maxi, vol);
            if (height[l] > height[h]) h--;
            else l++;
        }
        
        return maxi;
    }
};

int main() {
    Solution sol;

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << sol.maxArea(height) << endl;

    return 0;
}