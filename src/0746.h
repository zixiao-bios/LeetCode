#ifndef LEETCODE_0746_H
#define LEETCODE_0746_H

#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        /// pay[i] = min(pay[i-1] + cost[i-1], pay[i-2] + cost[i-2])
        /// pay[0] = 0, pay[1] = 0
        cost.push_back(-1);

        vector<int> pay(3);

        pay[0] = 0;
        pay[1] = 0;

        for (int i = 2; i < cost.size(); ++i) {
            pay[2] = min(pay[1] + cost[i - 1], pay[0] + cost[i - 2]);
            pay[0] = pay[1];
            pay[1] = pay[2];
        }

        return pay[2];
    }
};

#endif //LEETCODE_0746_H
