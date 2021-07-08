#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        if(m * n == 1) {
            if(word.length() != 1)
                return false;
            if(word[0] == board[0][0])
                return true;
            return false;
        }
        vector<vector<bool>> flag(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool r = exist(board, word, 0, flag, i, j);
                if(r == true)
                    return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string& word, int index, vector<vector<bool>>& flag, int i, int j) {
        if (index == word.length() - 1 && board[i][j] == word[index])
            return true;
        if(board[i][j] != word[index])
            return false;
        cout << board[i][j] << " " << i << " " << j << endl;

        bool r = false;
        flag[i][j] = true;
        if (i > 0 && flag [i - 1][j] == false) {
            r = exist(board, word, index + 1, flag, i - 1, j);
            if (r == true)
                return true;
        }
        if (i < board.size() - 1 && flag [i + 1][j] == false) {
            r = exist(board, word, index + 1, flag, i + 1, j);
            if (r == true)
                return true;
        }
        if (j > 0 && flag [i][j - 1] == false) {
            r = exist(board, word, index + 1, flag, i, j - 1);
            if (r == true)
                return true;
        }
        if (j < board[0].size() - 1 && flag[i][j + 1] == false) {
            r = exist(board, word, index + 1, flag, i, j + 1);
            if (r == true)
                return true;
        }
        flag[i][j] = false;
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    string word = "ABCCED";
    board = {{'a', 'a'}};
    word = "aaa";

    Solution solution;
    bool res = solution.exist(board, word);

    cout << "res: " << res << endl;
}