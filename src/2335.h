#ifndef LEETCODE_2335_H
#define LEETCODE_2335_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int fillCups(vector<int> &amount) {
        sort(amount.begin(), amount.end());
        if (amount[2] >= amount[0] + amount[1]) {
            return amount[2];
        } else {
            return (amount[0] + amount[1] - amount[2] + 1) / 2 + amount[2];
        }
    }
};


#endif //LEETCODE_2335_H
