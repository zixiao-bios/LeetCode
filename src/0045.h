#ifndef LEETCODE_0045_H
#define LEETCODE_0045_H

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int max_pos = 0;
        int step = 0;
        int end = 0;

        for (int i = 0; i < nums.size(); ++i) {
            max_pos = max(max_pos, i + nums[i]);

            if (i == end) {
                ++step;
                end = max_pos;

                if (end >= nums.size() - 1) {
                    break;
                }
            }
        }

        return step;
    }
};

#endif //LEETCODE_0045_H
