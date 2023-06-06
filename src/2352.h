#ifndef LEETCODE_2352_H
#define LEETCODE_2352_H

#include <vector>
#include <unordered_map>
#include <sstream>

using std::vector;

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        std::unordered_map<std::string, int> count;
        for (const auto &row: grid) {
            ++count[convert(row)];
        }

        int ans = 0;
        for (int i = 0; i < grid[0].size(); ++i) {
            ans += count[convert(get_col(grid, i))];
        }
        return ans;
    }

    std::string convert(const vector<int> &array) {
        std::ostringstream os;
        for (const auto &each: array) {
            os << each << ' ';
        }
        return os.str();
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

#endif //LEETCODE_2352_H
