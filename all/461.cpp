#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, z = x ^ y;
        while(z != 0) {
            if(z & 1 == 1) res++;
            z = z >> 1;
        }
        return res;
    }
};

int main() {
    int x = 1, y = 4;

    Solution solution;
    int res = solution.hammingDistance(x, y);
    cout << "res: " << res << endl;
}