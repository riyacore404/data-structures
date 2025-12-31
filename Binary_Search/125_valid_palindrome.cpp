/*
Platform: LeetCode
Problem: 125 - Valid Palindrome
Approach: Filtering + Reverse Comparison
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Convert to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // Keep only alphanumeric characters
        vector<char> v;
        for (char ch : s) {
            if (isalpha(ch) || isdigit(ch)) {
                v.push_back(ch);
            }
        }

        // Reverse and compare
        vector<char> rev(v);
        reverse(rev.begin(), rev.end());

        return v == rev;
    }
};

int main() {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << (sol.isPalindrome(s) ? "true" : "false") << endl;
    return 0;
}
