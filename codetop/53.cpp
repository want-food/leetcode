/*************************************************************************
	> File Name: 53.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 10:50:34 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		int r = 0, ans = nums[0];
		for (int i = 0; i < len; i++) {
			r = nums[i] + r;
			if(nums[i] < r) {
				nums[i] = r;
			}
			if(r < 0) {
				r = 0;
			}
			ans = max(nums[i], ans);
			cout << nums[i] << " " << ans << endl;
		}
		return ans;
    }
};

int main() {
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	nums = {-1,1};

	Solution solution;
	int ans = solution.maxSubArray(nums);
	cout << "ans: " << ans << endl;
}