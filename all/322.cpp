/*************************************************************************
	> File Name: 322.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Tue Jun 29 00:01:42 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	int res = -1;
    int coinChange(vector<int>& coins, int amount) {
		// // 1. 超出时间限制
		// coinChange(coins, amount, 0);
		// return res;
		
		// 2. 空间换时间
		if(amount == 0) return 0;
		        vector<int> res(amount+1, -1);
				        int n = coins.size();
						        for (int i = 0; i < n; i++) {
								            if(coins[i] > amount) break;
								            res[coins[i]] = 1;
								        }
								        for (int i = 0; i <= amount; i++) {
										            if(res[i] != -1) {
													                for (int j = 0; j < n; j++) {
																	                    int m = coins[j] + i;
																	                    if(m > amount) break;
																	                    if(res[m] == -1) res[m] = res[i] + 1;
																	                    else if(res[m] > res[i] + 1) res[m] = res[i] + 1;
																	                }
													            }
										        }
										        return res[amount];
    }
	void coinChange(vector<int>& coins, int amount, int depth) {
		if(amount == 0) {
			if(res == -1) res = depth;
			res = min(res, depth);
			return  ;
		}
		else if(amount < 0) 
			return;
		for (int i = 0; i < coins.size(); i++) {
			if(res != -1 && depth > res) continue;
			coinChange(coins, amount-coins[i], depth+1);
		}
	}
};

int main() {
	vector<int> coins = {1,1000000};
	int amount = 2;

	Solution solution;
	int res = solution.coinChange(coins, amount);
	cout << "res: " << res << endl;
}
