#ifndef LEETCODE_0451_H
#define LEETCODE_0451_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void quickSort(vector<pair<char, int>> &data, int start, int end) {
        if (start >= end) {
            return;
        }

        int l = start, r = end;
        auto key = data[l];

        while (l < r) {
            while (l < r and data[r].second <= key.second) {
                --r;
            }
            data[l] = data[r];

            while (l < r and data[l].second >= key.second) {
                ++l;
            }
            data[r] = data[l];
        }
        data[l] = key;

        quickSort(data, start, l - 1);
        quickSort(data, l + 1, end);
    }

    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (auto &each: s) {
            ++count[each];
        }

        vector<pair<char, int>> times(count.size());
        for (auto &each: count) {
            times.emplace_back(each);
        }

        quickSort(times, 0, times.size() - 1);

        string ans;
        for (auto &each: times) {
            for (int i = 0; i < each.second; ++i) {
                ans += each.first;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0451_H
