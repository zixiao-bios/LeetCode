#ifndef LEETCODE_1376_H
#define LEETCODE_1376_H

/**
 * 既然题目数据是反着给的（给定每个人的上司），那么就反着考虑，每个人向上司汇报，找出耗时最长的人的所需时间
 *
 * time[i]：索引为 i 的人需要的汇报时间
 * time[i] = time[par] + informTime[par]    , 其中 par = manager[i]
 */

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> time;

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        time = vector(n, -1);
        int max_time = 0;
        for (int i = 0; i < n; ++i) {
            max_time = std::max(max_time, need_time(i, manager, informTime));
        }
        return max_time;
    }

    int need_time(int i, const vector<int> &manager, const vector<int> &informTime) {
        if (time[i] == -1) {
            int par = manager[i];
            if (par == -1) {
                time[i] = 0;
            } else {
                time[i] = need_time(par, manager, informTime) + informTime[par];
            }
        }
        return time[i];
    }
};

#endif //LEETCODE_1376_H
