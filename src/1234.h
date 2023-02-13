#ifndef LEETCODE_1234_H
#define LEETCODE_1234_H

#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool check(const unordered_map<char, int> &target) {
        return all_of(target.begin(), target.end(), [](const pair<char, int> &a) {
            return a.second <= 0;
        });
    }

    int balancedString(string s) {
        unordered_map<char, int> num;
        int correct_num = s.size() / 4;
        for (auto &ch: s) {
            ++num[ch];
        }

        bool balance = true;
        for (auto &each: num) {
            if (each.second != correct_num) {
                balance = false;
                if (each.second > correct_num) {
                    each.second -= correct_num;
                } else {
                    each.second = 0;
                }
            } else {
                each.second = 0;
            }
        }
        if (balance) {
            return 0;
        }

        int ans = INT32_MAX;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            --num[s[right]];
            while (left <= right and check(num)) {
                ans = min(ans, right - left + 1);
                ++num[s[left]];
                ++left;
            }
        }
        return ans;
    }
};

#endif //LEETCODE_1234_H
