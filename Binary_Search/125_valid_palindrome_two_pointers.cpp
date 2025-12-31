/*
Platform: LeetCode
Problem: 125 - Valid Palindrome
Approach: Two Pointers (In-place, skipping non-alphanumeric)
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Convert string to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int l = 0, h = s.size() - 1;

        while (l < h) {
            // Skip non-alphanumeric characters
            while (l < h && !isalnum(s[l])) l++;
            while (l < h && !isalnum(s[h])) h--;

            if (s[l] != s[h]) return false;
            l++;
            h--;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << (sol.isPalindrome(s) ? "true" : "false") << endl;
    return 0;
}
