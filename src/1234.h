#ifndef LEETCODE_1234_H
#define LEETCODE_1234_H

#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<char, int> target_num;

    bool balance(const unordered_map<char, int> &num) {
        return all_of(target_num.begin(), target_num.end(), [&num](const pair<char, int> &each) {
            try {
                return num.at(each.first) == each.second;
            } catch (const exception &e) {
                return false;
            }
        });
    }

    int balancedString(string s) {
        unordered_map<char, int> total_num;
        int correct_num = s.size() / 4;

        for (auto &ch: s) {
            ++total_num[ch];
        }

        bool balance = true;
        for (auto &each: total_num) {
            if (each.second != correct_num) {
                balance = false;
                if (each.second > correct_num) {
                    target_num[each.first] = each.second - correct_num;
                }
            }
        }


    }
};

#endif //LEETCODE_1234_H
