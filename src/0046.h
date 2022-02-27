#ifndef LEETCODE_0046_H
#define LEETCODE_0046_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums, ans, 0);
        return ans;
    }

    void backtracking(vector<int> &nums, vector<vector<int>> &ans, int level) {
        if (level == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = level; i < nums.size(); ++i) {
            swap(nums[level], nums[i]);
            backtracking(nums, ans, level + 1);
            swap(nums[level], nums[i]);
        }
    }
};

#endif //LEETCODE_0046_H
