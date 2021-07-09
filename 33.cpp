/*************************************************************************
	> File Name: 33.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Mon Jul  5 11:13:54 2021
 ************************************************************************/

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size()-1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if(nums[mid] == target) return mid;
			if(left == right) break;
			if(nums[mid] < nums[right]) {
				if(target > nums[mid] && target <= nums[right]) {
					left = mid+1;
				}
				else {
					right = mid-1;
				}
			}
			else if(nums[mid] > nums[right]) {
				if(target < nums[mid] && target >= nums[left]) {
					right = mid-1;
				}
				else  {
					left = mid+1;
				}
			}
		}
		return -1;
    }
};

int main() {
	vector<int> nums = {1};
	int target = 0;

	Solution solution;
	int res = solution.search(nums, target);
	cout << "res: " << res << endl;
}