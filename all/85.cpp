#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 1.
        // int m = matrix.size(), n = matrix[0].size();
        // if(m * n == 0)
        //     return 0;
        // vector<vector<int>> len(m, vector<int>(n, 0));
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if(matrix[i][j] == '1') {
        //             len[i][j] = (j == 0 ? 1 : len[i][j - 1] + 1);
        //         }
        //     }
        // }
        // int res = 0;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if(matrix[i][j] == '0')
        //             continue;
        //         int MIN = len[i][j];
        //         for (int k = i; k < m; k++) {
        //             if(matrix[k][j] == '0')
        //                 break;
        //             MIN = min(MIN, len[k][j]);
        //             res = max(res, MIN * (k - i + 1));
        //         }
        //     }
        // }
        // return res;

        int m = matrix.size();
        if (m == 0) 
            return 0;
        
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < n; j++)
        { // 对于每一列，使用基于柱状图的方法
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--)
            {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j])
                {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++)
            {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<char>> board = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    board = {};

    Solution solution;
    int res = solution.maximalRectangle(board);
    cout << "res: " << res << endl;
}