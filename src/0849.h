#ifndef LEETCODE_0849_H
#define LEETCODE_0849_H

#include <vector>

class Solution {
public:
    int maxDistToClosest(std::vector<int> &seats) {
        int n = seats.size();
        std::vector<std::pair<int, int>> dis(n);

        int d = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                d = 0;
            }
            dis[i].first = d;
            if (d != INT_MAX) {
                ++d;
            }
        }

        d = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            if (seats[i] == 1) {
                d = 0;
            }
            dis[i].second = d;
            if (d != INT_MAX) {
                ++d;
            }
        }

        int ans = 1;
        for (const auto &each: dis) {
            ans = std::max(ans, std::min(each.first, each.second));
        }
        return ans;
    }
};

#endif //LEETCODE_0849_H
