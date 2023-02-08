#ifndef LEETCODE_0093_H
#define LEETCODE_0093_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ans;

    vector<string> restoreIpAddresses(string s) {
        vector<int> res(4);
        backtrace(s, res, 0, 0);
        return ans;
    }

    static int convert_to_ip_num(const string &s) {
        if (s.empty()) {
            return -1;
        }

        if (s[0] == '0') {
            if (s.size() == 1) {
                return 0;
            } else {
                return -1;
            }
        }

        try {
            int num = stoi(s);
            if (num <= 255) {
                return num;
            } else {
                return -1;
            }
        } catch (exception &e) {
            return -1;
        }
    }

    void backtrace(const string &s, vector<int> &res, int level, int offset) {
        if (level == 3) {
            res[level] = convert_to_ip_num(s.substr(offset));
            if (res[level] != -1) {
                string ip;
                for (auto &each: res) {
                    ip += '.';
                    ip += to_string(each);
                }
                ans.push_back(ip.substr(1));
            }
            return;
        }

        for (int i = 1; i < s.size() - offset + 1; ++i) {
            res[level] = convert_to_ip_num(s.substr(offset, i));
            if (res[level] == -1) {
                return;
            }
            backtrace(s, res, level + 1, offset + i);
        }
    }
};

#endif //LEETCODE_0093_H
