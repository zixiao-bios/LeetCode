#ifndef LEETCODE_1093_H
#define LEETCODE_1093_H

#include <vector>
#include <numeric>

using std::vector;

class Solution {
public:
    vector<double> sampleStats(vector<int> &count) {
        int tot = std::accumulate(count.begin(), count.end(), 0);
        vector<int> median_idx{tot / 2, (tot - 1) / 2};

        int min_v = INT32_MAX, max_v = INT32_MIN, mode, mode_n = 0, idx = 0;
        double mean = 0, median = 0;

        for (int i = 0; i < 256; ++i) {
            if (count[i] == 0) {
                continue;
            }

            min_v = std::min(min_v, i);
            max_v = std::max(max_v, i);
            mean += (static_cast<double>(i) * count[i]) / tot;

            if (count[i] > mode_n) {
                mode = i;
                mode_n = count[i];
            }

            for (const int &each: median_idx) {
                if (each >= idx and each < idx + count[i]) {
                    median += i * 0.5;
                }
            }

            idx += count[i];
        }

        return {static_cast<double>(min_v), static_cast<double>(max_v), mean, median, static_cast<double>(mode)};
    }
};

#endif //LEETCODE_1093_H
