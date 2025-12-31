/*
Platform: GeeksforGeeks
Problem: Tower of Hanoi
Approach: Recursion
Time Complexity: O(2^n)
Space Complexity: O(n)  // Recursive call stack
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Returns the minimum number of moves required to solve Tower of Hanoi
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 0) return 0;

        return 1 + towerOfHanoi(n - 1, from, aux, to)  // move n-1 disks to auxiliary
                 + towerOfHanoi(n - 1, aux, to, from); // move n-1 disks from auxiliary to target
    }
};

int main() {
    Solution sol;
    int n = 3; // number of disks

    cout << "Minimum number of moves for " << n << " disks: "
         << sol.towerOfHanoi(n, 1, 3, 2) << endl; // rods labeled 1 (source), 3 (target), 2 (aux)

    return 0;
}
