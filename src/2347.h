#ifndef LEETCODE_2347_H
#define LEETCODE_2347_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string bestHand(vector<int> &ranks, vector<char> &suits) {
        int n = ranks.size();

        bool flush = true;
        for (int i = 1; i < n; ++i) {
            if (suits[i] != suits[i - 1]) {
                flush = false;
                break;
            }
        }
        if (flush) {
            return "Flush";
        }

        unordered_map<int, int> map;
        for (auto &each: ranks) {
            ++map[each];
        }

        int max_num = 0;
        for (auto &each: map) {
            max_num = max(max_num, each.second);
        }

        if (max_num >= 3) {
            return "Three of a Kind";
        } else if (max_num == 2) {
            return "Pair";
        } else {
            return "High Card";
        }
    }
};

#endif //LEETCODE_2347_H
