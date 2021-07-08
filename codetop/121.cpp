/*************************************************************************
	> File Name: 121.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 14:00:14 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int ans = 0, len = prices.size();
		vector<int> nums(len - 1);
		for (int i = 0; i < len-1; i++) {
			prices[i] = prices[i+1] - prices[i];
		}
		for (int i = 0; i < len-1; i++) {
			if(i != 0)
				prices[i] = max(prices[i], prices[i-1] + prices[i]);
			if(prices[i] > ans) {
				ans = prices[i];
			}
		}
		return ans;
    }
};

int main() {
	vector<int> nums = {7,6,4,3,12};

	Solution solution;
	int res = solution.maxProfit(nums);
	cout << "res: " << res << endl;
}