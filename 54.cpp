/*************************************************************************
	> File Name: 54.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Mon Jul  5 09:12:11 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if(m == 0) return {};
		int n = matrix[0].size();
		if(n == 0) return {};

		vector<int> res;
		int limit = m * n, layer = 0, row = 0, col = 0;
		for (int i = 0; i < limit; i++) {
			if(row == layer && col == layer) {
				if(layer != 0 || (layer == 0 && !res.empty())) {
					layer++;
					row = layer, col = layer;
				}
			}
			res.push_back(matrix[row][col]);
			if(row == layer) {
				if(col != n-1-layer) {
					col++;
				}
				else {
					row++;
				}
			}
			else if(col == n-1-layer) {
				if(row != m-1-layer) {
					row++;
				}
				else {
					col--;
				}
			}
			else if(row == m-1-layer)  {
				if(col != layer) {
					col--;
				}
				else {
					row--;
				}
			}
			else if(col == layer) {
				if(row != layer) {
					row--;
				}
			}
		}
		return res;	
    }
};

int main() {
	vector<vector<int>> matrix = {
		{ 1, 2, 3, 4, 5},
		{ 6, 7, 8, 9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25},
	};
	matrix = {{1}};

	Solution solution;
	vector<int> res = solution.spiralOrder(matrix);
	cout << "res: " << endl;
	for (int i: res) {
		cout << i << " ";
	}
	cout << endl;
}