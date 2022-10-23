#ifndef LEETCODE_0069_1_H
#define LEETCODE_0069_1_H

/// 二分法

using namespace std;

class Solution {
public:
    int find(int start, int end, int target) {
        uint64_t mid = (start + end) / 2;

        if (mid * mid <= target and (mid + 1) * (mid + 1) > target) {
            return mid;
        } else if (mid * mid > target) {
            return find(start, mid - 1, target);
        } else {
            return find(mid + 1, end, target);
        }
    }

    int mySqrt(int x) {
        return find(0, x, x);
    }
};

#endif //LEETCODE_0069_1_H
