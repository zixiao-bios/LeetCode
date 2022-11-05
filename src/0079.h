#ifndef LEETCODE_0079_H
#define LEETCODE_0079_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction = {{1,  0},
                                        {-1, 0},
                                        {0,  1},
                                        {0,  -1}};
    int m, n;

    bool exist(vector<vector<char>> &board, string word) {
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtracking(board, visited, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool outOfBounds(int i, int j) {
        return i < 0 or i >= m or j < 0 or j >= n;
    }

    bool backtracking(const vector<vector<char>> &board,
                      vector<vector<bool>> &visited,
                      int i,
                      int j,
                      const string &word,
                      int level) {
        if (level == word.size()) {
            return true;
        }

        if (outOfBounds(i, j) or visited[i][j] or board[i][j] != word[level]) {
            return false;
        }

        visited[i][j] = true;
        for (auto &each: direction) {
            if (backtracking(board, visited, i + each.first, j + each.second, word, level + 1)) {
                return true;
            }
        }
        visited[i][j] = false;

        return false;
    }
};

#endif //LEETCODE_0079_H
