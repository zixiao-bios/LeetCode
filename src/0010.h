#ifndef LEETCODE_0010_H
#define LEETCODE_0010_H

using namespace std;

class Solution {
public:
    static bool equal(char a, char b) {
        if (a == '.' or b == '.') {
            return true;
        }

        return a == b;
    }

    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }

    bool match(const string &s, const string &p, int is, int ip) {
        if (is == s.size() and ip == p.size()) {
            return true;
        }

        if (is == s.size() and ip <= p.size() - 2 and p[ip + 1] == '*') {
            return match(s, p, is, ip + 2);
        }

        if (is >= s.size() or ip >= p.size()) {
            return false;
        }

        if (ip < p.size() - 1 and p[ip + 1] == '*') {
            if (equal(s[is], p[ip])) {
                // 当前s的字符与*匹配，可以选择匹配，或者不匹配
                if (match(s, p, is + 1, ip)) {
                    return true;
                } else if (match(s, p, is, ip + 2)) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return match(s, p, is, ip + 2);
            }
        }

        if (equal(s[is], p[ip])) {
            return match(s, p, is + 1, ip + 1);
        } else {
            return false;
        }
    }
};

#endif //LEETCODE_0010_H
