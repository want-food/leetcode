/*************************************************************************
	> File Name: 1.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Fri Jul  2 00:18:28 2021
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1. 
        // int n = nums.size();
		// vector<pair<int, int>> map;
		// for (int i = 0; i < n; i++) {
		// 	map.push_back({nums[i], i});
		// }
		// sort(map.begin(), map.end(), [](const auto& u, const auto& v) {
		// 	return u.first <= v.first;
		// });
		// int left = 0, right = nums.size() - 1;
		// while(left < right) {
		// 	if(map[left].first + map[right].first == target) {
		// 		return {map[left].second, map[right].second};
		// 	}
		// 	if(map[left].first + map[right].first < target) {
		// 		left++;
		// 	}
		// 	else {
		// 		right--;
		// 	}
		// }
		// return {-1, -1};

       // 2. unordered_map
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			int n = target - nums[i];
			auto it = map.find(n);
			if(it != map.end()) return {it->second, i};
			map[nums[i]] = i;
		}
		return {};
    }
};

int main() {
	// nums = [2,7,11,15], target = 9
	vector<int> nums = {2,7,11,15};
	int target = 9;

	Solution solution;
	vector<int> res = solution.twoSum(nums, target);
	cout << "res: " << endl;
	for (int i: res) {
		cout << i << " ";
	}
	cout << endl;
}