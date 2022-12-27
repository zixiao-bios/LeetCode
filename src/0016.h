#ifndef LEETCODE_0016_H
#define LEETCODE_0016_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());

        int gap = INT_MAX;
        int sum;
        int a, b, c;

        for (a = 0; a < nums.size() - 2; ++a) {
            b = a + 1;
            c = nums.size() - 1;

            while (b < c) {
                int t = nums[a] + nums[b] + nums[c];

                if (abs(t - target) < gap) {
                    // 更接近
                    gap = abs(t - target);
                    sum = t;
                }

                if (t < sum) {
                    ++b;
                } else {
                    --c;
                }
            }
        }

        return sum;
    }
};

#endif //LEETCODE_0016_H
