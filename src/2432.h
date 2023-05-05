#ifndef LEETCODE_2432_H
#define LEETCODE_2432_H

#include <vector>

using std::vector;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int max_duration = 0, last_end_time = 0, id;

        for (const auto &job: logs) {
            int duration = job[1] - last_end_time;
            if (duration > max_duration or (duration == max_duration and job[0] < id)) {
                max_duration = job[1] - last_end_time;
                id = job[0];
            }
            last_end_time = job[1];
        }

        return id;
    }
};

#endif //LEETCODE_2432_H
