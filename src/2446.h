#ifndef LEETCODE_2446_H
#define LEETCODE_2446_H

#include <vector>

using std::vector, std::string;

class Solution {
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2) {
        int start_1 = to_sec(event1[0]), end_1 = to_sec(event1[1]);
        int start_2 = to_sec(event2[0]), end_2 = to_sec(event2[1]);

        return not(end_1 < start_2 or end_2 < start_1);
    }

    int to_sec(const string &time) {
        int hour = std::stoi(time.substr(0, 2));
        int min = std::stoi(time.substr(time.find(':') + 1));
        return hour * 3600 + min * 60;
    }
};

#endif //LEETCODE_2446_H
