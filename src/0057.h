#ifndef LEETCODE_0057_H
#define LEETCODE_0057_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }

        if (newInterval[0] > intervals[intervals.size() - 1][1]) {
            // insert to end
            intervals.insert(intervals.end(), newInterval);
            return intervals;
        }

        bool finish_insert = false;
        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
            auto each = *it;

            if (newInterval[0] <= each[1]) {
                if (newInterval[1] < each[0]) {
                    // no overlap
                    intervals.insert(it, newInterval);
                } else {
                    // remove overlap
                    int left = min(each[0], newInterval[0]);
                    int right = max(each[1], newInterval[1]);
                    auto it_right = it;

                    while (true) {
                        each = *it;
                        if (each[0] <= right) {
                            // overlap
                            right = max(right, each[1]);

                            // don't use erase, to avoid data move cost
//                            it = intervals.erase(it);

                            (*it)[0] = -1;
                            ++it;

                            if (it == intervals.end()) {
                                // insert to end
                                intervals.insert(it, {left, right});
                                break;
                            }
                        } else {
                            // not overlap, jump out
                            intervals.insert(it, {left, right});
                            break;
                        }
                    }

                    // remove-erase
                    intervals.erase(
                            remove_if(intervals.begin(), intervals.end(), [](const vector<int> &a) { return a[0] == -1; }),
                            intervals.end()
                    );
                }

                finish_insert = true;
            }

            if (finish_insert) {
                break;
            }
        }

        return intervals;
    }
};

#endif //LEETCODE_0057_H
