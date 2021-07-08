#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // // 1. 暴力解法
        // int res = INT32_MIN;
        // for (int i = 0; i < nums.size(); i++) {
        //     int tmp = nums[i];
        //     res = max(res, tmp);
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         tmp = tmp * nums[j];
        //         res = max(tmp, res);
        //     }
        // }
        // return res;

        // 2.
        int Min = nums[0], Max = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            Max = max(nums[i], max(Max * nums[i], Min * nums[i]));
            Min = min(nums[i], min(Max * nums[i], Min * nums[i]));
            res = max(Max, res);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2,3,-2,4};

    Solution solution;
    int res = solution.maxProduct(nums);
    cout << "res: " << res << endl;
}