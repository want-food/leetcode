/*************************************************************************
	> File Name: 3.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun May 16 22:04:10 2021
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		// init
		int res = 0;
		int pos[128] = {0};
		for (int i = 0; i < 128; i++) {
			pos[i] = -1;
		}

		int begin = 0;
		int i ;
		for (i = 0; i < s.length(); i++) {
			if(pos[s[i]] == -1) {
				pos[s[i]] = i;
			}
			else {
				int pre = pos[s[i]];

				for (int j = begin; j < pre; j++) {
					pos[s[j]] = -1;
				}
				if(res < i - begin)
					res = i - begin;
				begin = pre+1;
				pos[s[i]] = i;
			}
		}
		if(res < i - begin)
			res = i - begin;
		return res;
	}
};

int main() {
	string s = " ";

	Solution solution;
	int res = solution.lengthOfLongestSubstring(s);
	cout << "res: " << res << endl;
}