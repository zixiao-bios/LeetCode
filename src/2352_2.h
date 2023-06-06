#ifndef LEETCODE_2352_2_H
#define LEETCODE_2352_2_H

#include <vector>
#include <map>

using std::vector;

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        std::map<std::vector<int>, int> count;
        for (const auto &row: grid) {
            ++count[row];
        }

        int ans = 0;
        for (int i = 0; i < grid[0].size(); ++i) {
            ans += count[get_col(grid, i)];
        }
        return ans;
    }

    std::vector<int> get_col(const vector<vector<int>> &grid, int i) {
        std::vector<int> res;
        res.reserve(grid.size());
        for (const auto &row: grid) {
            res.push_back(row[i]);
        }
        return res;
    }
};

#endif //LEETCODE_2352_2_H
