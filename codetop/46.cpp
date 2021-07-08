/*************************************************************************
	> File Name: 46.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon Jul  5 00:18:25 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
		// // 1. 自己的方法，广度遍历
		// vector<int> r;
		// permute(nums, 0, r);
		// return ans;

		// 2. 回溯
		DFS(nums, 0);
		return ans;
    }
	void DFS(vector<int>& nums, int index) {
		if(index == nums.size()) {
			ans.push_back(nums);
			return;
		}

		for (int i = index; i < nums.size(); i++) {
			swap(nums[index], nums[i]);
			DFS(nums, index+1);
			swap(nums[index], nums[i]);
		}
	}
	void permute(vector<int>& nums, int index, vector<int>& r) {
		if(index == nums.size()) {
			ans.push_back(r);
			return;
		}
		for (int i = 0; i <= r.size(); i++) {
			r.insert(r.begin()+i, nums[index]);
			permute(nums, index+1, r);
			r.erase(r.begin()+i);
		}
	}
};

int main() {
	vector<int> nums = {1,2,3};

	Solution solution;
	vector<vector<int>> res = solution.permute(nums);
	cout << "res: " << endl;
	for (vector<int>& vec: res) {
		for (int i: vec) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}