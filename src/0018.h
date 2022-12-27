#ifndef LEETCODE_0018_H
#define LEETCODE_0018_H

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;

        if (nums.size() < 4) {
            return ans;
        }

        sort(nums.begin(), nums.end());

        int a, b, c, d;

        int va, vb;
        bool first_a, first_b;

        auto update = [&](int &x, int vx, int limit, bool max) {
            if (max) {
                while (x < limit and nums[x] == vx) {
                    ++x;
                }
            } else {
                while (x > limit and nums[x] == vx) {
                    --x;
                }
            }
        };

        first_a = true;
        for (a = 0; a < nums.size() - 3; ++a) {
            if (!first_a) {
                update(a, va, nums.size() - 3, true);
            }
            va = nums[a];
            first_a = false;

            first_b = true;
            for (b = a + 1; b < nums.size() - 2; ++b) {
                if (!first_b) {
                    update(b, vb, nums.size() - 2, true);
                }
                vb = nums[b];
                first_b = false;

                c = b + 1;
                d = nums.size() - 1;

                while (c < d) {
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];

                    if (sum == target) {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});

                        update(c, nums[c], d, true);
                        update(d, nums[d], c, false);
                    } else if (sum < target) {
                        ++c;
                    } else {
                        --d;
                    }
                }
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0018_H
