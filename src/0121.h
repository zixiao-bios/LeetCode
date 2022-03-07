#ifndef LEETCODE_0121_H
#define LEETCODE_0121_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int profit = 0, minPrice = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i] - minPrice);
        }

        return profit;
    }
};

#endif //LEETCODE_0121_H
