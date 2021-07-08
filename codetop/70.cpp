/*************************************************************************
	> File Name: 70.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon Jul  5 23:58:10 2021
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		if(n == 0 || n == 1) return n;
		int first = 0, second = 1;
		for (int i = 0; i < n; i++) {
			int tmp = second;
			second += first;
			first = tmp;
		}
		return second;
    }
};

int main() {
	int n = 3;

	Solution solution;
	int res = solution.climbStairs(n);
	cout << "res: " << res << endl;
}