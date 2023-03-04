#ifndef LEETCODE_982_2_H
#define LEETCODE_982_2_H

#include <vector>

using std::vector;

class Solution {
public:
    int countTriplets(vector<int> &nums) {
        vector<int> count(1 << 16, 0);

        for (auto &x: nums) {
            for (auto &y: nums) {
                ++count[x & y];
            }
        }

        int ans = 0;
        for (auto &k: nums) {
            for (int i = 0; i < count.size(); ++i) {
                if ((k & i) == 0) {
                    ans += count[i];
                }
            }
        }

        return ans;
    }
};

#endif //LEETCODE_982_2_H
