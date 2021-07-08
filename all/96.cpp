#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // G(n): 表示长度为n的序列构成的不同二叉搜索树的个数

        // // 1. 迭代
        // vector<int> res(n + 1, 0);
        // for (int i = 0; i <= n; i++) {
        //     if(i == 0 || i == 1) {
        //         res[i] = 1;
        //         continue;
        //     }
        //     int tmp = 0;
        //     for (int j = 0; j < i; j++) {
        //         tmp += res[j] * res[i - 1 - j];
        //     }
        //     res[i] = tmp;
        // }
        // return res[n];

        // 2. 递归
        if(n == 1 || n == 0) return 1;

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += numTrees(i) * numTrees(n - 1 - i);
        }
        return res;
    }
};

int main() {
    int n = 3;

    Solution solution;
    int res = solution.numTrees(n);
    cout << "res: " << res << endl;
}