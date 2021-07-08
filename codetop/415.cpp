/*************************************************************************
	> File Name: 415.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 22:24:42 2021
 ************************************************************************/

#include <iostream>


using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
		string ans = "";
		int len1 = num1.length()-1, len2 = num2.length()-1;
		int carry = 0, n;
		while(len1 >= 0 && len2 >= 0) {
			n = num1[len1--] - '0' + num2[len2--] - '0' + carry;
			if(n >= 10) {
				n -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			ans = char(n + '0') + ans;
		}
		while(len1 >= 0) {
			n = num1[len1--] - '0' + carry;
			if(n >= 10) {
				n -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			ans = char(n + '0') + ans;
		}
		while(len2 >= 0) {
			n = num2[len2--] - '0' + carry;
			if(n >= 10) {
				n -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			ans = char(n + '0') + ans;
		}
		if(carry == 1) {
			ans = "1" + ans;
		}
		return ans;
    }
};

int main() {
	string a = "123", b = "934";

	Solution solution;
	string res = solution.addStrings(a, b);
	cout << "res: " << res << endl;
}