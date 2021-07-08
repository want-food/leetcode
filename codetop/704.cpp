/*************************************************************************
	> File Name: 704.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 23:54:15 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		return biSearch(nums, target, 0, nums.size()-1);
    }
	int biSearch(vector<int>& nums, int target, int left, int right) {
		// cout << left << " " << right << endl;
		if(left > right) return -1;
		if(left == right) {
			if(nums[left] == target) return left;
			return -1;
		}
		int mid = (left + right) / 2;
		if(nums[mid] == target) return mid;
		
		if(nums[mid] < target) {
			return biSearch(nums, target, mid+1, right);
		}
		return biSearch(nums, target, left, mid-1);
	}
};

int main() {
	vector<int> nums = {-1,0,3,5,9,12};
	int target = 2;

	Solution solution;
	int res = solution.search(nums, target);
	cout << "res: " << res << endl;
}