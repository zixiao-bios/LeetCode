#ifndef LEETCODE_0447_H
#define LEETCODE_0447_H

#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:

    static int get_dis(const vector<int> &p1, const vector<int> &p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }

    int numberOfBoomerangs(vector<vector<int>> &p) {
        auto n = p.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            std::unordered_map<int, int> dis_num;
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                }

                ++dis_num[Solution::get_dis(p[i], p[j])];
            }

            for (const auto &each: dis_num) {
                if (each.second >= 2) {
                    ans += each.second * (each.second - 1);
                }
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0447_H
