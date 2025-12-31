/*
Platform: LeetCode
Problem: 278 - First Bad Version
Approach: Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

// ⚠️ LeetCode provides this API internally
// For local testing, we mock it below
bool isBadVersion(int version) {
    return version >= 4; // example: version 4 is the first bad version
}

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, h = n;
        
        while (l < h) {
            int m = l + (h - l) / 2; // Prevent overflow
            
            if (isBadVersion(m)) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        
        return l;
    }
};

int main() {
    Solution sol;
    int n = 10;
    cout << "First Bad Version: " << sol.firstBadVersion(n) << endl;
    return 0;
}
