#ifndef LEETCODE_0077_H
#define LEETCODE_0077_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> output(k, 0);
        vector<vector<int>> ans;

        backtracking(n, output, ans, 0, -1);

        return ans;
    }

    void backtracking(int n, vector<int> &output, vector<vector<int>> &ans, int level, int pre) {
        if (level == output.size()) {
            ans.push_back(output);
            return;
        }

        for (int i = pre + 1; i < n; ++i) {
            output[level] = i + 1;
            backtracking(n, output, ans, level + 1, i);
        }
    }
};

#endif //LEETCODE_0077_H
