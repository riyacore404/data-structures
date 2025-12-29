/*
Platform: LeetCode
Problem: 121 - Best Time to Buy and Sell Stock
Approach: Single Pass / Tracking Minimum Price
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Minimum price seen so far
        int maxProfit = 0;       // Maximum profit achievable

        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);         // Update minimum price
            maxProfit = max(maxProfit, prices[i] - minPrice); // Update max profit
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
