#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> pattern(n + 1, 0);
        for (int i = 1; i < n+1; i++) {
            int res = INT32_MAX;
            for (int j = 1; j * j <= i; j++) {
                res = min(res, pattern[i-j*j]);
            }
            pattern[i] = res + 1;
        }
        return pattern[n];
    }
};

int main() {
    int n = 13;

    Solution solution;
    int res = solution.numSquares(n);
    cout << "res: " << res << endl;
}