#ifndef LEETCODE_2208_H
#define LEETCODE_2208_H

#include <vector>
#include <queue>
#include <numeric>

class Solution {
public:
    int halveArray(std::vector<int> &nums) {
        double target = std::accumulate(nums.begin(), nums.end(), 0.0) / 2;
        std::priority_queue<double> prior_queue{nums.begin(), nums.end()};

        double process = 0.;
        int step = 0;
        while (process < target) {
            process += prior_queue.top() / 2;
            ++step;
            prior_queue.push(prior_queue.top() / 2);
            prior_queue.pop();
        }

        return step;
    }
};

#endif //LEETCODE_2208_H
