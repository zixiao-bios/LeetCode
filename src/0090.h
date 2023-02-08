#ifndef LEETCODE_0090_H
#define LEETCODE_0090_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        ans.emplace_back();
        for (int i = 1; i <= nums.size(); ++i) {
            vector<int> res(i);
            backtrace(nums, res, i, 0, 0);
        }

        return ans;
    }

    void backtrace(const vector<int> &nums, vector<int> &res, int len, int level, int offset) {
        if (level == len) {
            ans.push_back(res);
            return;
        }

        for (int i = offset; i < nums.size();) {
            int num = nums[i];
            res[level] = num;
            backtrace(nums, res, len, level + 1, i + 1);

            while (i < nums.size() and nums[i] == num) {
                ++i;
            }
        }
    }
};

#endif //LEETCODE_0090_H
