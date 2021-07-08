/*************************************************************************
	> File Name: 88.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 22:33:43 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		// // 1. 排序合并后
		// for (int i = m; i < m+n; i++) {
		// 	nums1[i] = nums2[i - m];
		// }
		// sort(nums1.begin(), nums1.end());
		
		// 2. 直接合并
		if(nums2.size() == 0) return;
		if(nums1.size() == 0) {
			nums1 = nums2;
			return;
		}
		int l1 = 0, l2 = 0;
		while(l1 < m && l2 < n) {
			if(nums1[l1] <= nums2[l2]) {
				l1++;
			}
			else {
				for (int i = m-1; i >= l1; i--) {
					nums1[i+1] = nums1[i];
				}
				nums1[l1] = nums2[l2];
				cout << l1 << " " << nums1[l1] << " " << nums1[l1+1] << endl;
				l1++;
				l2++;
				m++;
			}
		}
		cout << "l1: " << l1 << endl;
		cout << "l2: " << l2 << endl;
		if(l2 == nums2.size()) return;
		while(l1 < nums1.size()) {
			nums1[l1++] = nums2[l2++];
		}
    }
};

int main() {
	vector<int> nums1 = {2,3,0,0};
	vector<int> nums2 = {1,2};
	int m = 2, n = 2;

	Solution solution;
	solution.merge(nums1, m, nums2, n);
	cout << "res: " << endl;
	for (int i: nums1) {
		cout << i << " ";
	}
	cout << endl;
}