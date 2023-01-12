#ifndef LEETCODE_0078_H
#define LEETCODE_0078_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> res;
        backtrace(nums, res, 0);
        return ans;
    }

    void backtrace(const vector<int> &nums, vector<int> &res, int level) {
        ans.push_back(res);

        if (level == nums.size()) {
            return;
        }

        for (int i = level; i < nums.size(); ++i) {
            res.push_back(nums[i]);
            backtrace(nums, res, i + 1);
            res.erase(res.end() - 1);
        }
    }
};

#endif //LEETCODE_0078_H
