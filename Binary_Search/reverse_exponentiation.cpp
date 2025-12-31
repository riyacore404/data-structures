/*
Platform: GeeksforGeeks
Problem: Reverse Exponentiation
Approach: Digit Manipulation + Power Calculation
Time Complexity: O(d)   // d = number of digits in n
Space Complexity: O(1)
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverseExponentiation(int n) {
        int m = n;
        int p = 0;

        // Reverse the digits of n to form exponent p
        while (m / 10) {
            p += (m % 10) * (m / 10);
            m = m / 10;
        }
        p += m;

        return pow(n, p);
    }
};

int main() {
    Solution sol;
    int n = 12;

    cout << "Result: " << sol.reverseExponentiation(n) << endl;
    return 0;
}
