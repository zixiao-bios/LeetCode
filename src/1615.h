#ifndef LEETCODE_1615_H
#define LEETCODE_1615_H

#include <vector>
#include <numeric>

using std::vector;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector map(n, vector(n, false));
        vector degree(n, 0);

        for (const auto &road: roads) {
            map[road[0]][road[1]] = true;
            map[road[1]][road[0]] = true;
            ++degree[road[0]];
            ++degree[road[1]];
        }

        int max_rank = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                max_rank = std::max(max_rank, degree[i] + degree[j] - map[i][j]);
            }
        }

        return max_rank;
    }
};

#endif //LEETCODE_1615_H
