/*************************************************************************
	> File Name: 4.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Fri Jul  2 00:46:33 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		nums1.push_back(INT32_MAX);
		nums2.push_back(INT32_MAX);
		int l1 = 0, l2 = 0;
		int sum = len1 + len2;
		int mid = (sum - 1) / 2;
		for (int i = 0; i < mid; i++) {
			if(nums1[l1] < nums2[l2]) {
				l1++;
			}
			else {
				l2++;
			}
		}
		if(sum % 2 == 1) return min(nums1[l1], nums2[l2]);
		if(l1 != len1 || l2 != len2) { 
			return 1.0 * (nums1[l1] + nums2[l2]) / 2;
		}
		if(l1 == len1) {
			if(l2 == 0) return 1.0 * (nums2[l2] + nums2[l2 + 1]) / 2;
			return 1.0 * (nums2[w2])
		}
    }
};

int main() {
	vector<int> nums1 = {1,3};
	vector<int> nums2 = {2};

	Solution solution;
	double res = solution.findMedianSortedArrays(nums1, nums2);
	cout << "res: " << res << endl;
}
