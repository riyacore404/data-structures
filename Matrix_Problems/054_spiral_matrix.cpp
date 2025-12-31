/*
Platform: LeetCode
Problem: 54 - Spiral Matrix
Approach: Boundary Traversal (Simulation)
Time Complexity: O(n * m)  // visit each element once
Space Complexity: O(1) extra, O(n*m) for output
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> temp;

        if (matrix.empty()) return temp;

        int n = matrix.size();
        int m = matrix[0].size();

        int t = 0, b = n - 1, l = 0, r = m - 1;
        while (t <= b && l <= r) {
            // top row
            for (int i = l; i <= r; i++) temp.push_back(matrix[t][i]);
            t++;

            // right column
            for (int i = t; i <= b; i++) temp.push_back(matrix[i][r]);
            r--;

            // bottom row
            if (t <= b) {
                for (int i = r; i >= l; i--) temp.push_back(matrix[b][i]);
                b--;
            }

            // left column
            if (l <= r) {
                for (int i = b; i >= t; i--) temp.push_back(matrix[i][l]);
                l++;
            }
        }

        return temp;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> res = sol.spiralOrder(matrix);

    cout << "Spiral order: [ ";
    for (int num : res) cout << num << " ";
    cout << "]" << endl;

    return 0;
}
