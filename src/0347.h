#ifndef LEETCODE_0347_H
#define LEETCODE_0347_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int quickSelection(vector<pair<int, int>> &times, int start, int end) {
        auto key = times[start];
        int l = start, r = end;

        while (l < r) {
            while (l < r and times[r].second <= key.second) {
                --r;
            }
            times[l] = times[r];

            while (l < r and times[l].second >= key.second) {
                ++l;
            }
            times[r] = times[l];
        }

        times[l] = key;
        return l;
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> count;

        for (auto &each: nums) {
            ++count[each];
        }

        vector<pair<int, int>> times(count.size());
        for (auto &each: count) {
            times.emplace_back(each);
        }

        int start = 0, end = times.size() - 1;
        while (true) {
            int i = quickSelection(times, start, end);

            if (i + 1 == k) {
                break;
            }

            if (i + 1 < k) {
                start = i + 1;
            } else {
                end = i - 1;
            }
        }

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            ans[i] = times[i].first;
        }

        return ans;
    }
};

#endif //LEETCODE_0347_H
