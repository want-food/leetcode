/*************************************************************************
	> File Name: 169.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon Jun 14 00:08:21 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		// 1. 
		if(nums.size() == 1) return nums[0];
		unordered_map<int, int> map;
		int limit = nums.size() / 2;
		for (int i = 0; i < nums.size(); i++) {
			if(map.find(nums[i]) != map.end()) {
				map[nums[i]]++;
				if(map[nums[i]] > limit) return nums[i];
			}
			else {
				map[nums[i]] = 1;
			}
		}
		return -1;
    }
};

int main() {
	vector<int> nums = {3,2,3,3};

	Solution solution;
	int res = solution.majorityElement(nums);
	cout << "res: " << res << endl;
}
