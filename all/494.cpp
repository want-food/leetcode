#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 1. 
        int res = 0;
        findTarget(nums, 0, target, 0, res);
        return res;
    }
    void findTarget(vector<int>& nums, int index, int& target, int sum, int& res) {
        if(index == nums.size()) {
            if(sum == target) res++;
            return;
        }
        findTarget(nums, index+1, target, sum + nums[index], res);
        findTarget(nums, index+1, target, sum - nums[index], res);
    }
};

int main() {
    vector<int> nums = {1};
    int target = 1;

    Solution solution;
    int res = solution.findTargetSumWays(nums, target);
    cout << "res: " << res << endl;
}