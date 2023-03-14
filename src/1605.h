#ifndef LEETCODE_1605_H
#define LEETCODE_1605_H

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
        auto m = rowSum.size();
        auto n = colSum.size();
        vector ans(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = std::min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }

        return ans;
    }
};

#endif //LEETCODE_1605_H
