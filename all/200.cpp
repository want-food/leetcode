/*************************************************************************
	> File Name: 200.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon Jun 14 00:23:34 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		int res = 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if(grid[i][j] == '1') {
					dfs(grid, i, j, m, n);
					res ++;
				}
			}
		}
		return res;
    }
	void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
		grid[i][j] = '0';
		if(i > 0 && grid[i-1][j] == '1') dfs(grid, i-1, j, m, n);
		if(i < m-1 && grid[i+1][j] == '1') dfs(grid, i+1, j, m, n);
		if(j > 0 && grid[i][j-1] == '1') dfs(grid, i, j-1, m, n);
		if(j < n-1 && grid[i][j+1] == '1') dfs(grid, i, j+1, m, n);
	}
};

int main() {
	vector<vector<char>> grid = {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'},
	};
	grid = {{'1'}};

	Solution solution;
	int res = solution.numIslands(grid);
	cout << "res: " << res << endl;
}
