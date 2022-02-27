#ifndef LEETCODE_35_H
#define LEETCODE_35_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nums;
    int target;

    int searchInsert(vector<int> &n, int t) {
        this->nums = n;
        this->target = t;

        return findIn(0, n.size() - 1);
    }

    int findIn(int start, int end) {
        if (start > end) {
            return start;
        }

        int mid = start + ((end - start) >> 1);
        if (this->nums[mid] == target) {
            return mid;
        } else if (this->nums[mid] > target) {
            return findIn(start, mid - 1);
        } else {
            return findIn(mid + 1, end);
        }
    }
};

#endif //LEETCODE_35_H
