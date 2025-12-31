/*
Platform: LeetCode
Problem: 2643 - Row with Maximum Ones
Approach: Row-wise Counting
Time Complexity: O(n * m)  // n = rows, m = columns
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();

        int i = 0;
        int maxi = 0, idx = 0;
        for (vector<int>& v : mat) {
            int freq = count(v.begin(), v.end(), 1);
            if (maxi < freq) {
                maxi = freq;
                idx = i;
            }
            i++;
        }

        return {idx, maxi};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 1, 1},
        {1, 1, 0},
        {0, 0, 1}
    };

    vector<int> res = sol.rowAndMaximumOnes(mat);
    cout << "Row index: " << res[0] << ", Max ones: " << res[1] << endl;

    return 0;
}
