#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 1 || len == 0) return 0;
        vector<int> res(len, 0);
        for (int i = 1; i < len; i++) {
            res[i] = res[i] - res[i-1];
        }
        sort(res.begin(), res.end());
        int ans = max(res[len-1], 0) + max(res[len-2], 0);
        for (int i = 1; i < len; i++) {
            if(res[i-1] > 0) {
                
            }
        }

    }
};

int main() {
    vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
    // prices = {1,4,2};
    // prices = {1,2,3,4,5};
    // prices = {1,0};

    Solution solution;
    int res = solution.maxProfit(prices);
    cout << "res: " << res << endl;
}