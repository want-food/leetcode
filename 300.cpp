/*************************************************************************
	> File Name: 300.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Mon Jul  5 22:36:50 2021
 ************************************************************************/

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int n = nums.size(), ans = 0;
		vector<int> vec(n, 1);
		for (int i = n-2; i >= 0; i--) {
			int j = i+1, t = 0;
			while(j < n) {
				if(nums[i] < nums[j]) {
					t = max(t, vec[j]);
				}
				j++;
			}
			vec[i] += t; // j == n ? 0 : vec[j];
			if(ans < vec[i]) ans = vec[i];
		}
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << endl;
		return ans;
    }
};

int main() {
	vector<int> nums = {0,1,0,3,2,3};

	Solution solution;
	int res = solution.lengthOfLIS(nums);
	cout << "res: " << res << endl;
}