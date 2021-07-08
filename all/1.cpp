/*************************************************************************
	> File Name: 1.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun May 16 20:19:27 2021
 ************************************************************************/

// 1. 两数之和

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		// // 1. 暴力解法
		// for (int i = 0; i < nums.size()-1; i++) {
		// 	for (int j = i+1; j < nums.size(); j++) {
		// 		if(nums[i] + nums[j] == target)
		// 			return {i, j};
		// 	}
		// }
		// return {};

		// 2. 哈希
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			auto it = map.find(target - nums[i]);

			if(it != map.end()) {
				cout << it->first << "  " << it->second << endl;
				return {it->second, i};
			}
			map[nums[i]] = i;
		}
		return {};
	}
};

int main() {
	vector<int> nums = {3, 2, 4};
	int target = 6;

	Solution solution;
	vector<int> res = solution.twoSum(nums, target);
	for (int& n: res) cout << n << " ";
	cout << endl;
}
