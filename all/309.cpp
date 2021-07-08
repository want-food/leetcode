#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> res(n, vector<int> (3));
        // res[i][0]: 表示当前手上有
        // res[i][1]: 表示手上没有，当前处于解封期
        // res[i][2]: 表示手上没有，当前过了解封期
        res[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            res[i][0] = max(res[i-1][0], res[i-1][2] - prices[i]);
            res[i][1] = res[i-1][0] + prices[i];
            res[i][2] = max(res[i-1][1], res[i-1][2]);
        }
        return max(res[n-1][1], res[n-1][2]);
    }
};

int main() {
    vector<int> prices = {1,2,3,0,2};

    Solution solution;
    int res = solution.maxProfit(prices);
    cout << "res: " << res << endl;
}