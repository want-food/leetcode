/*************************************************************************
	> File Name: 42.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Mon Jul  5 22:04:51 2021
 ************************************************************************/

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		// // 1. 自己的方法
		// int left = 0, right = height.size()-1, ans = 0;
		// vector<int> vec(height.size(), 0);
		// while(left < right) {
		// 	int Min = min(height[left], height[right]);
		// 	for (int i = left+1; i <= right-1; i++) {
		// 		vec[i] = max(vec[i], Min - height[i]);
		// 	}
		// 	if(height[left] < height[right]) {
		// 		left++;
		// 	}
		// 	else {
		// 		right--;
		// 	}
		// }
		// for (int i = 0; i < height.size(); i++) {
		// 	cout << vec[i] << " ";
		// 	ans += vec[i];
		// }
		// cout << endl;
		// return ans;

		// 2. 官方解法：当前的面积只受到两边最高的高度限制。
		if(height.size() == 2) return 0;
		int left = 0, len = height.size(), right = len-1, res = 0, H = 0;

		while(left < right) {
			int h = min(height[left], height[right]);
			if(h > H) {
				H = h;
			}
			else {
				res += H - h;
			}
			if(height[left] <= height[right]) left++;
			else right--;
		}
		return res;
    }
};

int main() {
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

	Solution solution;
	int res = solution.trap(height);
	cout << "res: " << res << endl;
}