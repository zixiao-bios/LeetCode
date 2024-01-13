#ifndef LEETCODE_2182_H
#define LEETCODE_2182_H

#include <vector>

using std::string;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        std::vector<int> num(26, 0);
        for (const auto &ch: s) {
            ++num[static_cast<int>(ch - 'a')];
        }

        int forbid_idx = -1, max_idx = 25, last_idx = -1, repeat = 0;
        string ans;

        while(true) {
            // update max_idx
            while (max_idx >= 0 and num[max_idx] == 0) {
                --max_idx;
            }

            // find max char to fill
            int p = max_idx;
            while (p >= 0 and (num[p] == 0 or p == forbid_idx)) {
                --p;
            }
            if (p < 0) {
                break;
            }

            ans.push_back(static_cast<char>(p + 'a'));
            --num[p];
            repeat = (p == last_idx ? repeat + 1 : 1);
            forbid_idx = (repeat >= repeatLimit ? p : -1);
            last_idx = p;
        }

        return ans;
    }
};

#endif //LEETCODE_2182_H
