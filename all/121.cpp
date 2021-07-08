#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int MIN = prices[0];
        int res = 0;
        for (int i = 1; i < len; i++) {
            MIN = min(MIN, prices[i]);
            res = max(res, prices[i] - MIN);
        }
        return res;
    }
};

int main() {
    vector<int> prices = {7,6,5,4,3};

    Solution solution;
    int res = solution.maxProfit(prices);
    cout << "res: " << res << endl;
}