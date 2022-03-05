#ifndef LEETCODE_0949_H
#define LEETCODE_0949_H

#include <vector>

using namespace std;

class Solution {
public:
    int hour = -1, minute = -1;

    string largestTimeFromDigits(vector<int>& arr) {
        vector<bool> used(arr.size(), false);
        vector<int> ans(arr.size(), -1);

        backtracking(0, used, arr, ans);

        if (hour == -1) {
            return "";
        } else {
            string s = "";
            if (hour < 10) {
                s += "0";
            }
            s += to_string(hour);
            s += ":";
            if (minute < 10) {
                s += "0";
            }
            s += to_string(minute);
            return s;
        }
    }

    void backtracking(int level, vector<bool> &used, vector<int> &arr, vector<int> &ans) {
        if (level == 4) {
            // 检查合法性
            int h = ans[0] * 10 + ans[1];
            int m = ans[2] * 10 + ans[3];
            if (h > 23 or m > 59) {
                return;
            }

            // 合法，检查是否更大
            if (h > hour or (h == hour and m > minute)) {
                hour = h, minute = m;
            }
            return;
        }

        for (int i = 0; i < arr.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                ans[level] = arr[i];
                backtracking(level + 1, used, arr, ans);
                used[i] = false;
            }
        }
    }
};

#endif //LEETCODE_0949_H
