/*
Platform: LeetCode
Problem: 74 - Search a 2D Matrix
Approach: Binary Search on Flattened Matrix
Time Complexity: O(log(m*n))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, h = m * n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int val = matrix[mid / n][mid % n];

            if (val == target) return true;
            if (val > target) h = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target = 3;

    cout << (sol.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;
    return 0;
}
