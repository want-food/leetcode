/*************************************************************************
	> File Name: 31.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Wed May 26 23:11:43 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		int left, right;
		for (left = nums.size() - 2; left >= 0; left--) {
			if(nums[left] < nums[left+1]) {
				break;
			}
		}
		if(left == -1) {
			reverse(nums.begin(), nums.end());
			return;
		}
		for (right = nums.size() - 1; right > left; right--) {
			if (nums[right] > nums[left]) {
				break;
			}
		}
		cout << "left: " << left << endl;
		cout << "right: " << right << endl;
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		reverse(nums.begin() + left + 1, nums.end());
	}
};

int main() {
	vector<int> nums = {1,3,3};

	Solution solution;
	solution.nextPermutation(nums);
	cout << "res: " << endl;
	for (int i: nums) {
		cout << i << " ";
	}
	cout << endl;
}