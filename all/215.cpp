#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // // 1. 快排
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() - k];

        // 2. 快速选择
        return quickCh(nums, nums.size() - k, 0, nums.size()-1);
    }
    int quickCh (vector<int>& nums, int k, int begin, int end) {
        int tmp = nums[end];
        int mid = begin;
        for (int i = begin; i < end; i++) {
            if(nums[i] < tmp) {
                swap(nums[i], nums[mid++]);
            }
        }
        swap(nums[mid], nums[end]);
        if(mid == k) return nums[mid];
        if(mid < k) return quickCh(nums, k, mid+1, end);
        if(mid > k) return quickCh(nums, k, begin, mid-1);
        return 0;
    }

};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    Solution solution;
    int res = solution.findKthLargest(nums, k);
    cout << "res: " << res << endl;
}