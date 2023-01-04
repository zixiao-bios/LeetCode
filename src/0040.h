#ifndef LEETCODE_0040_H
#define LEETCODE_0040_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int n;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.rbegin(), candidates.rend());

        n = candidates.size();
        vector<int> res;
        backtrace(candidates, target, res, 0);

        return ans;
    }

    void backtrace(const vector<int> &data, int remain, vector<int> &res, int start) {
        if (remain == 0) {
            ans.push_back(res);
            return;
        } else if (remain < 0){
            return;
        }

        for (int i = start; i < n;) {
            res.push_back(data[i]);
            backtrace(data, remain - data[i], res, i + 1);
            res.erase(res.end() - 1);

            int v = data[i];
            while (i < n and data[i] == v) {
                ++i;
            }
        }
    }
};

#endif //LEETCODE_0040_H
