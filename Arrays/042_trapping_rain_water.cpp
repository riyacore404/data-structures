/*
Platform: LeetCode
Problem: 42 - Trapping Rain Water
Approach 1: Monotonic Stack
Time Complexity: O(n)
Space Complexity: O(n)

Approach 2: Two Pointers
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Approach 1: Monotonic Stack
class SolutionStack {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;

                int left = st.top();
                int width = i - left - 1;
                int bounded_height = min(height[i], height[left]) - height[top];
                water += width * bounded_height;
            }
            st.push(i);
        }

        return water;
    }
};

// Approach 2: Two Pointers
class SolutionTwoPointers {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        
        int l = 0, h = n - 1;
        int leftmax = height[0], rightmax = height[h];
        while (l < h) {
            if (leftmax < rightmax) {
                leftmax = max(leftmax, height[l + 1]);
                water += leftmax - height[l + 1];
                l++;
            } else {
                rightmax = max(rightmax, height[h - 1]);
                water += rightmax - height[h - 1];
                h--;
            }
        }

        return water;
    }
};

int main() {
    SolutionStack sol1;
    SolutionTwoPointers sol2;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Water Trapped (Stack): " << sol1.trap(height) << endl;
    cout << "Water Trapped (Two Pointers): " << sol2.trap(height) << endl;
    return 0;
}
