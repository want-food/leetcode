/*************************************************************************
	> File Name: 48.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon May 31 23:04:05 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int len = matrix.size();
		if(len == 1) return;

		for (int i = 0; i < len / 2; i++) {
			vector<int> tmp;
			for (int j = 0; j < len - 2 * i - 1; j++) {
				tmp.push_back(matrix[i][j + i]);
				// up <- left
				matrix[i][j + i] = matrix[len - 1 - i - j][i];
				// left <- bottom
				matrix[len - 1 - i - j][i] = matrix[len - 1 - i][len - i - j - 1];
				// bottom <- right
				matrix[len - 1 - i][len - i - j - 1] = matrix[i + j][len - i - 1];
				// right <- up
				matrix[i + j][len - i - 1] = tmp[j];
			} 
			// up: [i][j + i]
			// left: [len - 1 - j - i][i]
			// bottom: [len - i - 1][len - i - j - 1]
			// right: [i + j][len - i - 1]
		}
    }
};

int main() {
	vector<vector<int>> nums = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};

	nums = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16},
	};

	Solution solution;
	solution.rotate(nums);
	cout << "res: " << endl;
	for (vector<int>& vec:  nums) {
		for (int i: vec) {
			cout << i << "\t";
		}
		cout << endl;
	}
	cout << endl;
} 
