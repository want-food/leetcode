/*************************************************************************
	> File Name: 200.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Mon Jul  5 09:42:11 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		int m = grid.size(); 
		if(m == 0) return 0;
		int n = grid[0].size();
		if(n == 0) return 0;

		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if(grid[i][j] == '1') {
					ans++;
					DFS(grid, i, j, m, n);
				}
			}
		}
		return ans;
    }
	void DFS(vector<vector<char>>& matrix, int i, int j, int& m, int& n) {
		if(matrix[i][j] == '0') return;
		matrix[i][j] = '0';
		if(i > 0) DFS(matrix, i-1, j, m, n);
		if(i < m-1) DFS(matrix, i+1, j, m, n);
		if(j > 0) DFS(matrix, i, j-1, m, n);
		if(j < n-1) DFS(matrix, i, j+1, m, n);
	}
};

int main() {
	vector<vector<char>> matrix = {
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	};

	Solution solution;
	int res = solution.numIslands(matrix);
	cout << "res: " << res << endl;
}