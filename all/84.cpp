#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // // 1. 
        // int len = heights.size(), res = 0;
        // for (int i = 0; i < len; i++) {
        //     int left = i, right = i;
        //     for (; left >= 0; left--) {
        //         if(heights[left] < heights[i])
        //             break;
        //     }
        //     for (; right < len; right++) {
        //         if(heights[right] < heights[i])
        //             break;
        //     }
        //     res = max(res, heights[i] * (right - left - 1));
        // }
        // return res;

        // // 2.
        // int len = heights.size(), res = 0;
        // vector<int> left(len, -1);
        // vector<int> right(len, -1);
        // for (int i = 0; i < len; i++) {
        //     int l = i, r = i;
        //     if(i > 0 && heights[i] <= heights[i - 1]) {
        //         l = left[i - 1];
        //         r = right[i - 1];
        //     }
        //     for (; l >= 0; l--) {
        //         if(heights[l] < heights[i])
        //             break;
        //     }
        //     for (; r < len; r++) {
        //         if(heights[r] < heights[i])
        //             break;
        //     }
        //     left[i] = l + 1;
        //     right[i] = r - 1;
        //     res = max(res, heights[i] * (r - l - 1));
        // }
        // return res;

        // 3. 官方解法，单调栈
        int len = heights.size(), res = 0;
        vector<int> left(len, -1), right(len, -1);
        stack<int> stk;
        for (int i = 0; i < len; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left[i] = (stk.empty() ? -1 : stk.top());
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = len - 1; i >= 0; i--) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            right[i] = (stk.empty() ? len : stk.top());
            stk.push(i);
        }
        for (int i = 0; i < len; i++) {
            res = max(heights[i] * (right[i] - left[i] - 1), res);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2, 1, 5, 6, 2, 3};
    // nums = {2, 4};

    Solution solution;
    int res = solution.largestRectangleArea(nums);
    cout << "res: " << res << endl;
}