/*
Platform: GeeksforGeeks
Problem: Aggressive Cows
Approach: Binary Search on Answer
Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    // Check if we can place k cows with at least minDis distance
    bool canPlace(vector<int> &stalls, int k, int minDis) {
        int cows = 1;
        int prev = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - prev >= minDis) {
                cows++;
                prev = stalls[i];
            }
            if (cows == k) return true;
        }
        return false;
    }

public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int n = stalls.size();
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlace(stalls, k, mid)) {
                ans = mid;        // valid → try larger minimum distance
                low = mid + 1;
            } else {
                high = mid - 1;   // invalid → reduce distance
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    cout << "Maximum minimum distance: "
         << sol.aggressiveCows(stalls, k) << endl;

    return 0;
}
