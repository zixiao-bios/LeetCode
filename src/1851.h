#ifndef LEETCODE_1851_H
#define LEETCODE_1851_H

#include <vector>
#include <queue>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries) {
        std::sort(intervals.begin(), intervals.end());

        vector<std::pair<int, int>> que;
        que.reserve(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            que.emplace_back(queries[i], i);
        }
        std::sort(que.begin(), que.end());

        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[1] - a[0] > b[1] - b[0];
        };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> queue(cmp);

        vector<int> ans(queries.size(), -1);
        int p = 0;
        for (const auto &q: que) {
            while (p < intervals.size() and intervals[p][0] <= q.first) {
                queue.push(intervals[p]);
                ++p;
            }
            while (!queue.empty() and queue.top()[1] < q.first) {
                queue.pop();
            }
            if (!queue.empty()) {
                ans[q.second] = queue.top()[1] - queue.top()[0] + 1;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_1851_H
