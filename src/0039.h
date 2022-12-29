#ifndef LEETCODE_0039_H
#define LEETCODE_0039_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> res;
        dfs(candidates, 0, res, target);
        return ans;
    }

    bool dfs(const vector<int> &candidates, int idx, vector<int> &res, int target) {
        if (target == 0) {
            ans.push_back(res);
            return false;
        }

        if (target < 0 or idx >= candidates.size()) {
            return false;
        }

        res.push_back(candidates[idx]);
        bool small = dfs(candidates, idx, res, target - candidates[idx]);
        res.erase(res.end() - 1);

        if (small) {
            dfs(candidates, idx + 1, res, target);
        }

        return true;
    }
};

#endif //LEETCODE_0039_H
