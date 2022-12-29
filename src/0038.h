#ifndef LEETCODE_0038_H
#define LEETCODE_0038_H

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        if (n == 1) {
            return s;
        }

        for (int i = 0; i < n - 1; ++i) {
            s = getDescribe(s);
        }

        return s;
    }

    string getDescribe(const string &s) {
        string res;
        char last_ch = s[0];
        int count = 0;

        for (auto &ch: s) {
            if (ch != last_ch) {
                res += to_string(count);
                res += last_ch;
                count = 1;
                last_ch = ch;
            } else {
                ++count;
            }
        }

        res += to_string(count);
        res += last_ch;

        return res;
    }
};

#endif //LEETCODE_0038_H
