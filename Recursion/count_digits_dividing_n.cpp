/*
Platform: GeeksforGeeks
Problem: Count Digits that Divide N
Approach: Digit Extraction + Modulo Check
Time Complexity: O(d)  // d = number of digits in n
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Counts the digits in n that evenly divide n
    int evenlyDivides(int n) {
        int m = n, cnt = 0;

        while (m) {
            int d = m % 10;
            if (d && n % d == 0) cnt++;  // Ignore zero and check divisibility
            m /= 10;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    int n = 1012;

    cout << "Number of digits in " << n 
         << " that divide it: " << sol.evenlyDivides(n) << endl;

    return 0;
}
