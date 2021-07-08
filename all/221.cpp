#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 1. 暴力解法
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                    }
                    if(res < dp[i][j]) res = dp[i][j];
                }
            }
        }
        return res * res;
    }
};

int main () {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };

    Solution solution;
    int res = solution.maximalSquare(matrix);
    cout << "res: " << res << endl;
}