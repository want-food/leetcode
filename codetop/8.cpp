/*************************************************************************
	> File Name: 8.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Tue Jul  6 01:00:29 2021
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
		long ans = 0, plus = 1;
		int i = 0;
		for ( ; i < s.length(); i++) {
			if(s[i] != ' ') break;
		}
		if(s[i] == '-') {
			plus = -1;
			i++;
		}
		else if(s[i] == '+') {
			i++;
		}
		for ( ; i < s.length(); i++) {
			if(s[i] >= '0' && s[i] <= '9') {
				ans = ans * 10 + s[i] - '0';
				if(ans > INT32_MAX) break;
			}
			else break;
		}
		ans = ans * plus;
		if(ans > INT32_MAX) return INT32_MAX;
		if(ans < INT32_MIN) return INT32_MIN;
		return ans;
    }
};

int main() {
	string s = "   -42";
	s = "20000000000000000000";

	Solution solution;
	int ans = solution.myAtoi(s);
	cout << "res: " << ans << endl;
}