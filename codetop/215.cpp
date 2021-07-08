/*************************************************************************
	> File Name: 215.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Fri Jul  2 23:29:40 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		// // 1. 完整快速排序
		// sort(nums.begin(), nums.end(), [](const auto& u, const auto& v) {
		// 	return u > v;
		// });
		// return nums[k-1];

		// // 2. 部分快排
		// int res = getKthMax(nums, nums.size() - k, 0, nums.size() - 1);
		// return res;

		// 3. 堆排序
		for (int i = 0; i < k; i++) {
			maxHeapify(nums, nums.size() / 2 - 1);
			if(i < k-1) {
				swap(nums[0], nums[nums.size() - 1]);
				nums.pop_back();
			}
		}
		return nums[0];
    }
	void maxHeapify(vector<int>& nums, int index) {
		if(2 * index + 1 >= nums.size()) return ;
		for (int i = index; i >= 0; i--) {
			int l = 2 * i + 1, r = 2 * i + 2, Max;
			if(r >= nums.size() || nums[l] >= nums[r]) {
				Max = l;
			}
			else {
				Max = r;
			}
			if(nums[i] < nums[Max]) {
				swap(nums[i], nums[Max]);
				maxHeapify(nums, Max);
			}
		}
	}
	int getKthMax(vector<int>& nums, int k, int left, int right) {
		int target = nums[right], mid = left;
		for (int i = left; i < right; i++) {
			if(nums[i] <= target) {
				swap(nums[mid++], nums[i]);
			}
		}
		swap(nums[right], nums[mid]);
		if(mid == k) return nums[mid];
		if(mid < k) return getKthMax(nums, k, mid+1, right);
		return getKthMax(nums, k, left, mid-1);
	}
};

int main() {
	vector<int> nums = {3,2,3,1,2,4,5,5,6};
	int k = 4;

	Solution solution;
	int res = solution.findKthLargest(nums, k);
	cout << "res: " << res << endl;
}