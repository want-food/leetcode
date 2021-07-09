/*************************************************************************
	> File Name: 718.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Tue Jul  6 09:35:04 2021
 ************************************************************************/

#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
		// // 1. 动态规划
		// int m = nums1.size(), n = nums2.size();
		// vector<vector<int>> dp(m, vector<int>(n, 0));
		// int ans = 0;
		// for (int i = 0; i < m; i++) {
		// 	for (int j = 0; j < n; j++){
		// 		if(i == 0 || j == 0) {
		// 			if(nums1[i] == nums2[j]) dp[i][j] = 1;
		// 		}
		// 		else {
		// 			if(nums1[i] != nums2[j]) dp[i][j] = 0;
		// 			else dp[i][j] = dp[i-1][j-1] + 1;
		// 		}
		// 		if(ans < dp[i][j]) ans = dp[i][j];
		// 	}
		// }
		// return ans;

		// 2. 滑动窗口
		int len_1 = nums1.size(), len_2 = nums2.size(), ans = 0;
		for (int i = 0; i < len_1; i++) {
			int n = 0;
			for (int j = 0; j < len_2; j++) {
				if(i + j >= len_1 || j >= len_2) break;
				// cout << nums1[i+j] << " " << nums2[j] << endl;
				if(nums1[i+j] == nums2[j]) {
					n += 1;
					ans = max(ans, n);
				}
				else {
					n = 0;
				}
			}
		}
		for (int i = 0; i < len_2; i++) {
			int n = 0;
			for (int j = 0; j < len_1; j++) {
				if(i + j >= len_2 || j >= len_1) break;
				if(nums2[i+j] == nums1[j]) {
					n += 1;
					ans = max(ans, n);
				}
				else {
					n = 0;
				}
			}
		}
		return ans;
    }
};

int main() {
	vector<int> nums1 = {1,2,3,2,1};
	vector<int> nums2 = {3,2,1,4,7};

	Solution solution;
	int res = solution.findLength(nums1, nums2);
	cout << "res: " << res << endl;
}
