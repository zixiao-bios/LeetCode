#ifndef LEETCODE_0018_2_H
#define LEETCODE_0018_2_H

#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }

        std::sort(nums.begin(), nums.end());

        std::unordered_map<int, int> count;
        for (const auto &num: nums) {
            ++count[num];
        }

        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 and nums[i] == nums[i - 1]) {
                continue;
            }

            --count[nums[i]];
            long t1 = static_cast<long>(target) - nums[i];
            if (t1 < 3l * nums[i]) {
                ++count[nums[i]];
                continue;
            }

            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 and nums[j] == nums[j - 1]) {
                    continue;
                }

                --count[nums[j]];
                long t2 = t1 - nums[j];
                if (t2 < 2l * nums[j]) {
                    ++count[nums[j]];
                    continue;
                }

                for (int k = j + 1; k < nums.size() - 1; ++k) {
                    if (k > j + 1 and nums[k] == nums[k - 1]) {
                        continue;
                    }

                    --count[nums[k]];
                    long t3 = t2 - nums[k];
                    if (t3 < nums[k] or t3 < INT32_MIN or t3 > INT32_MAX) {
                        ++count[nums[k]];
                        continue;
                    }

                    if (count[static_cast<int>(t3)] > 0) {
                        ans.push_back({nums[i], nums[j], nums[k], static_cast<int>(t3)});
                    }

                    ++count[nums[k]];
                }
                ++count[nums[j]];
            }
            ++count[nums[i]];
        }

        return ans;
    }
};

#endif //LEETCODE_0018_2_H
