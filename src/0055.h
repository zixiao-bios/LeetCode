#ifndef LEETCODE_0055_H
#define LEETCODE_0055_H

#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i <= reach) {
                reach = max(reach, i + nums[i]);
                if (reach >= nums.size() - 1) {
                    return true;
                }
            } else {
                return false;
            }
        }

        return false;
    }
};

#endif //LEETCODE_0055_H
