#ifndef LEETCODE_0189_H
#define LEETCODE_0189_H

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int cache;
        int n = nums.size();
        int i, j, start;

        start = 0;

        for (int t = 0; t < n;) {
            i = start;
            cache = nums[i];

            do {
                j = (i + k) % n;
                swap(nums[j], cache);
                ++t;
                i = j;
            } while (i != start);

            ++start;
        }
    }
};

#endif //LEETCODE_0189_H
