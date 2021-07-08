/*************************************************************************
	> File Name: 1.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 00:59:26 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		map[nums[0]] = 0;
		int n = nums.size();
		for (int i = 1; i < n; i++) {
			int r = target - nums[i];
			if(map.find(r) != map.end()) {
				return {map[r], i};
			}
			map[nums[i]] = i;
		}
		return {};
    }
};

int main() {
	vector<int> nums = {3,2,4};
	int target = 6;

	Solution solution;
	vector<int> res = solution.twoSum(nums, target);
	cout << "res:" << endl;
	for (int i: res) {
		cout << i << " ";
	}
	cout << endl;
}