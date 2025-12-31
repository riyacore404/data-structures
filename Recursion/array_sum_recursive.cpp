/*
Platform: GeeksforGeeks
Problem: Sum of Elements in an Array
Approach: Recursion (Backward Traversal)
Time Complexity: O(n)
Space Complexity: O(n)  // Recursive call stack
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper recursive function
    int summ(vector<int>& arr, int i, int sum) {
        if (i < 0) return sum;
        return summ(arr, i - 1, sum + arr[i]);
    }

    // Public function to compute array sum
    int arraySum(vector<int>& arr) {
        int n = arr.size();
        return summ(arr, n - 1, 0);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Sum of array elements: " << sol.arraySum(arr) << endl;
    return 0;
}
