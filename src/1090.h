#ifndef LEETCODE_1090_H
#define LEETCODE_1090_H

#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit) {
        auto n = values.size();
        std::vector<std::pair<int, int>> data;
        data.reserve(n);
        for (int i = 0; i < n; ++i) {
            data.emplace_back(labels[i], values[i]);
        }

        std::sort(data.begin(), data.end(),
                  [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
                      if (a.second == b.second) {
                          return a.first < b.first;
                      } else {
                          return a.second > b.second;
                      }
        });

        int ans = 0, set_num = 0;
        std::unordered_map<int, int> label_use;
        for (const auto &each: data) {
            if (label_use.find(each.first) != label_use.end()) {
                if (label_use[each.first] < useLimit) {
                    ++label_use[each.first];
                    ans += each.second;
                    ++set_num;
                } else {
                    continue;
                }
            } else {
                label_use[each.first] = 1;
                ans += each.second;
                ++set_num;
            }

            if (set_num == numWanted) {
                break;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_1090_H
