#ifndef LEETCODE_1653_H
#define LEETCODE_1653_H

using std::string;

class Solution {
public:
    int minimumDeletions(string s) {
        int delete_num = 0;
        for (const auto &ch: s) {
            if (ch == 'a') {
                ++delete_num;
            }
        }

        int ans = delete_num;
        for (const auto &ch : s) {
            if (ch == 'a') {
                --delete_num;
            } else {
                ++delete_num;
            }
            ans = std::min(ans, delete_num);
        }

        return ans;
    }
};

#endif //LEETCODE_1653_H
