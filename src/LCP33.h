#ifndef LEETCODE_LCP33_H
#define LEETCODE_LCP33_H

/**
 * 首先肯定是先升级水桶，再蓄水
 * 假设蓄水 k 次后，所有水缸都达到最低水量
 * 则有 k * bucket[i] >= vat[i]
 * bucket[i] >= vat[i] / k
 * 即每个水桶需要的升级次数也就确定了
 * 遍历每个可能的 k 即可
 */

#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;

class Solution {
public:
    int storeWater(vector<int> &bucket, vector<int> &vat) {
        int max_vat = *std::max_element(vat.begin(), vat.end());
        if (max_vat == 0) {
            return 0;
        }

        auto n = vat.size();
        int ans = INT32_MAX;
        for (int k = 1; k < ans; ++k) {
            int step = 0;
            for (int i = 0; i < n; ++i) {
                int target_bucket = std::ceil(static_cast<double>(vat[i]) / k);
                if (target_bucket > bucket[i]) {
                    step += target_bucket - bucket[i];
                }
            }
            ans = std::min(ans, step + k);
        }
        return ans;
    }
};

#endif //LEETCODE_LCP33_H
