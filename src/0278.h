#ifndef LEETCODE_278_H
#define LEETCODE_278_H

class Solution {
public:
    bool isBadVersion(int n);

    int firstBadVersion(int n) {
        return findIn(1, n);
    }

    int findIn(int start, int end) {
        int mid = start + (end - start) / 2;
        if (isBadVersion(mid)) {
            if (!isBadVersion(mid - 1)) {
                return mid;
            }
            return findIn(start, mid - 1);
        } else {
            return findIn(mid + 1, end);
        }
    }
};

#endif //LEETCODE_278_H
