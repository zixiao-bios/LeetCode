#ifndef LEETCODE_1792_H
#define LEETCODE_1792_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            double da = double(a.first + 1) / (a.second + 1) - double(a.first) / a.second;
            double db = double(b.first + 1) / (b.second + 1) - double(b.first) / b.second;
            return da < db;
        };
        priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(cmp)> p_queue(cmp);

        for (auto &each: classes) {
            p_queue.emplace(each[0], each[1]);
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto add = p_queue.top();
            p_queue.pop();
            ++add.first, ++add.second;
            p_queue.push(add);
        }

        double total = 0;
        while (!p_queue.empty()) {
            total += double(p_queue.top().first) / p_queue.top().second;
            p_queue.pop();
        }
        return total / classes.size();
    }
};

#endif //LEETCODE_1792_H
