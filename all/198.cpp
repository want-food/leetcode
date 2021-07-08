/*************************************************************************
	> File Name: 198.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon Jun 14 00:17:22 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
		int len = nums.size();
		vector<int> yes(len, 0);
		vector<int> no (len, 0);

		yes[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			yes[i] = no[i-1] + nums[i];
			no [i] = max(yes[i-1], no[i-1]);
		}
		return max(yes[len-1], no[len-1]);
    }
};

int main() {
	vector<int> nums = {1};

	Solution solution;
	int res = solution.rob(nums);
	cout << "res: " << res << endl;
}
