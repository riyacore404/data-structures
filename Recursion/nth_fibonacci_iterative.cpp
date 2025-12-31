/*
Platform: GeeksforGeeks / LeetCode
Problem: Nth Fibonacci Number
Approach: Iterative (Dynamic Programming, Space Optimized)
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int nthFibonacci(int n) {
        if (n <= 1) return n;

        int prev1 = 0, prev2 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};

int main() {
    Solution sol;
    int n = 10;

    cout << "The " << n << "th Fibonacci number is: " 
         << sol.nthFibonacci(n) << endl;
    return 0;
}
