/*
Platform: GeeksforGeeks
Problem: Print numbers from 1 to N
Approach: Recursion
Time Complexity: O(n)
Space Complexity: O(n)  // Recursive call stack
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void printTillN(int n) {
        if (n == 0) return;
        printTillN(n - 1);   // Recursive call
        cout << n << " ";    // Print after recursive call
    }
};

int main() {
    Solution sol;
    int n = 10;

    cout << "Numbers from 1 to " << n << ": ";
    sol.printTillN(n);
    cout << endl;

    return 0;
}
