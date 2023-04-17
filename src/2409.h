#ifndef LEETCODE_2409_H
#define LEETCODE_2409_H

#include <vector>

using std::string;

bool operator<(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

bool operator==(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first == b.first and a.second == b.second;
}

class Solution {
public:
    std::vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        std::pair<int, int> a_arrive, a_leave, b_arrive, b_leave;
        a_arrive = get_month_day(arriveAlice);
        a_leave = get_month_day(leaveAlice);
        b_arrive = get_month_day(arriveBob);
        b_leave = get_month_day(leaveBob);

        std::pair<int, int> both_arrive = a_arrive < b_arrive ? b_arrive : a_arrive;
        std::pair<int, int> both_leave = a_leave < b_leave ? a_leave : b_leave;
        return count_days(both_arrive, both_leave);
    }

    static std::pair<int, int> get_month_day(const string &s) {
        auto pos = s.find('-');
        return {std::stoi(s.substr(0, pos)), std::stoi(s.substr(pos + 1))};
    }

    int count_days(const std::pair<int, int> &a, const std::pair<int, int> &b) {
        if (b < a) {
            return 0;
        }

        int count = 0;
        for (int i = a.first; i < b.first; ++i) {
            count += days[i];
        }
        count -= a.second - 1;
        count += b.second;
        return count;
    }
};

#endif //LEETCODE_2409_H
