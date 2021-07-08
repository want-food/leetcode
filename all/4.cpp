#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();

		bool odd = (len1 + len2) % 2 == 1 ? true : false;
		// 如果有一个是空的
		if(odd == true) {
			if (len1 == 0)
				return nums2[len2 / 2];
			else if (len2 == 0)
				return nums1[len1 / 2];
		}
		else {
			if (len1 == 0)
				return 1.0 * (nums2[len2 / 2] + nums2[len2 / 2 - 1]) / 2;
			else if (len2 == 0)
				return 1.0 * (nums1[len1 / 2] + nums1[len1 / 2 - 1]) / 2;
		}

		int mid;
		if (odd == true)
			mid = (len1 + len2) / 2 + 1;
		else
			mid = (len1 + len2) / 2;

		nums1.push_back(INT32_MAX);
		nums2.push_back(INT32_MAX);
		int left = 0, right = 0;
		for (int i = 0; i < mid; i++) {
			if(nums1[left] <= nums2[right]) {
				left++;
			}
			else {
				right++;
			}
		}
		if(left == 0) {
			if(odd)
		}
	}
};

int main() {
	vector<int> num1 = {1,2};
	vector<int> num2 = {3};

	Solution solution;
	double res = solution.findMedianSortedArrays(num1, num2);
	cout << "res: " << res << endl;
}