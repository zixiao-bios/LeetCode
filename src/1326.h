#ifndef LEETCODE_1326_H
#define LEETCODE_1326_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int> &ranges) {
        vector<pair<int, int>> data(ranges.size());
        for (int i = 0; i < ranges.size(); ++i) {
            data[i] = {i - ranges[i], i + ranges[i]};
        }
        sort(data.begin(), data.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
        });

        int right = 0;
        int num = 0;
        for (int i = 0;;) {
            if (right >= n) {
                return num;
            }

            if (i >= data.size() or data[i].first > right) {
                return -1;
            }

            int r = 0;
            while (i < data.size() and data[i].first <= right) {
                r = max(r, data[i].second);
                ++i;
            }

            ++num;
            right = r;
        }
    }
};

#endif //LEETCODE_1326_H
