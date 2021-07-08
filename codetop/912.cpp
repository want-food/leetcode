/*************************************************************************
	> File Name: 912.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 00:47:28 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
		return nums;
    }
	void quickSort(vector<int>& nums, int left, int right) {
		if(left < right) {
			int mid = randomized_partition(nums, left, right);
			quickSort(nums, left, mid-1);
			quickSort(nums, mid+1, right);
		}
	}
	int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
	int partition(vector<int>& nums, int left, int right) {
		int n = nums[right], mid = left;
		for (int i = left; i < right; i++) {
			if(nums[i] < n) {
				swap(nums[mid++], nums[i]);
			}
		}
		swap(nums[mid], nums[right]);
		return mid;
	}
};

int main() {
	vector<int> nums = {5,2,3,1};

	Solution solution;
	vector<int> res = solution.sortArray(nums);
	cout << "res: " << endl;
	for (int i: res) {
		cout << i << " ";
	}
	cout << endl;
}