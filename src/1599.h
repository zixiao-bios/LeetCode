#ifndef LEETCODE_1599_H
#define LEETCODE_1599_H

#include <vector>

using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost) {
        int profit = 0, max_profit = -1;
        int step = 0, max_profit_step;
        int wait = 0, i = 0;

        while (true) {
            if (i < customers.size()) {
                wait += customers[i];
                ++i;
            } else if (wait == 0) {
                break;
            }

            profit += min(wait, 4) * boardingCost - runningCost;
            wait -= min(wait, 4);
            ++step;

            if (profit > max_profit) {
                max_profit = profit;
                max_profit_step = step;
            }
        }

        if (max_profit > 0) {
            return max_profit_step;
        } else {
            return -1;
        }
    }
};

#endif //LEETCODE_1599_H
