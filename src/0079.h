#ifndef LEETCODE_0079_H
#define LEETCODE_0079_H

#include <vector>

using namespace std;

class Solution {
public:
    int m, n;
    bool find = false;
    vector<vector<bool>> visited;
    vector<vector<int>> direction = {{0,  1},
                                     {0,  -1},
                                     {1,  0},
                                     {-1, 0}};

    bool exist(vector<vector<char>> &board, string word) {
        m = board.size(), n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtracking(i, j, board, 0, word);
                if (find) {
                    return true;
                }
            }
        }

        return false;
    }

    void backtracking(int i, int j, vector<vector<char>> &board, int pos, const string &word) {
        if (pos == word.size()) {
            find = true;
            return;
        }

        if (i < 0 or i >= m or j < 0 or j >= n) {
            return;
        }

        if (visited[i][j] or board[i][j] != word[pos]) {
            return;
        }

        visited[i][j] = true;

        for (auto &each: direction) {
            backtracking(i + each[0], j + each[1], board, pos + 1, word);
        }

        visited[i][j] = false;
    }
};

#endif //LEETCODE_0079_H
