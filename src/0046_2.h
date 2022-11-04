#ifndef LEETCODE_0046_2_H
#define LEETCODE_0046_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<bool> use(n, false);
        vector<int> output(n);

        backtracking(nums, use, output, 0);

        return ans;
    }

    void backtracking(vector<int> &nums, vector<bool> &use, vector<int> &output, int level) {
        if (level == n) {
            ans.push_back(output);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!use[i]) {
                output[level] = nums[i];
                use[i] = true;

                backtracking(nums, use, output, level + 1);

                use[i] = false;
            }
        }
    }
};

#endif //LEETCODE_0046_2_H
