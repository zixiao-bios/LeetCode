#ifndef LEETCODE_0047_H
#define LEETCODE_0047_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        vector<bool> used(nums.size(), false);
        backtrace(nums, res, used);
        return ans;
    }

    void backtrace(const vector<int> &nums, vector<int> &res, vector<bool> &used) {
        if (res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        int last = 11;
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i] and nums[i] != last) {
                used[i] = true;
                res.push_back(nums[i]);

                backtrace(nums, res, used);

                res.erase(res.end() - 1);
                used[i] = false;

                last = nums[i];
            }
        }
    }
};

#endif //LEETCODE_0047_H
