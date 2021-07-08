/*************************************************************************
	> File Name: 69.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Tue Jul  6 00:51:50 2021
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
		if(x < 0) return -1;
		if(x == 0 || x == 1) return x;

		long left  = 0, right = x;
		while(left < right) {
			if(left == right - 1) return left;
			long mid = (left + right) / 2, t = mid * mid;
			if(x == t) 
				return mid;
			else if(x > t) 
				left = mid;
			else if(x < t) 
				right = mid;
		}
		return -1;
    }
};

int main() {
	int n = 2147395599;

	Solution solution;
	int ans = solution.mySqrt(n);
	cout << "res: " << ans << endl;
}