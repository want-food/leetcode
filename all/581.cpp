#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1, right = -1;
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if(nums[i] >= nums[i+1]) {
                if(left == -1) left = i;
                if(i == n-2) right = i+1;
            }
            else {
                // if(left == -1) continue;
                if(nums[i] < nums[i+1] && nums[i] < nums[i-1]) right = i;
            }
        }
        cout << left << " " << right << endl;
        if(left == -1) return 0;
        return right - left + 1;
    }
};

int main() {
    vector<int> nums = {2,6,4,8,10,9,15};
    nums = {1,3,4,5,2};

    Solution solution;
    int res = solution.findUnsortedSubarray(nums);
    cout << "res: " << res << endl;
}