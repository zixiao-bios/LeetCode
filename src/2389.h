#ifndef LEETCODE_2389_H
#define LEETCODE_2389_H

#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;

class Solution {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        std::sort(nums.begin(), nums.end());

        vector<int> prefix_sum(nums.size() + 1, 0);
        for (int i = 1; i < nums.size() + 1; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }

        for (auto &each: queries) {
            each = find_lidx_in(prefix_sum, 0, prefix_sum.size() - 1, each);
        }
        return queries;
    }

    /// 返回目标元素在 data 中的索引，若 data 中没有 target，则返回小于 target 的最大元素的索引
    /// \param data 升序
    /// \param start
    /// \param end
    /// \param target 一定 >= data[start]
    /// \return
    int find_lidx_in(const vector<int> &data, int start, int end, int target) {
        if (end - start == 1) {
            if (target >= data[end]) {
                return end;
            } else {
                return start;
            }
        }

        int mid = (start + end) / 2;
        if (target >= data[mid]) {
            return find_lidx_in(data, mid, end, target);
        } else {
            return find_lidx_in(data, start, mid, target);
        }
    }
};

#endif //LEETCODE_2389_H
