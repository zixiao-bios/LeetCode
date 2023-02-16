#ifndef LEETCODE_2341_H
#define LEETCODE_2341_H

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int> &nums) {
        unordered_map<int, bool> even;
        int pair_num = 0;
        for (int &each: nums) {
            if (even.find(each) != even.end()) {
                even[each] = !even[each];
            } else {
                even[each] = false;
            }
            if (even[each]) {
                ++pair_num;
            }
        }
        return {pair_num, int(nums.size()) - 2 * pair_num};
    }
};

#endif //LEETCODE_2341_H
