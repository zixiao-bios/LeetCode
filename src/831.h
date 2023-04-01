#ifndef LEETCODE_831_H
#define LEETCODE_831_H

using std::string;

class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            return email(s);
        } else {
            return phone(s);
        }
    }

    static string phone(string &s) {
        for (auto it = s.begin(); it != s.end();) {
            if (*it >= '0' and *it <= '9') {
                ++it;
            } else {
                it = s.erase(it);
            }
        }

        static string prefix[]{"***-***-",
                               "+*-***-***-",
                               "+**-***-***-",
                               "+***-***-***-"};

        string ans{prefix[s.size() - 10]};
        ans += s.substr(s.size() - 4, 4);
        return ans;
    }

    static string email(string &s) {
        string ans;
        ans += s[0];
        ans += "*****";
        ans += s[s.find('@') - 1];
        ans += s.substr(s.find('@'));
        for (auto &ch: ans) {
            if (ch >= 'A' and ch <= 'Z') {
                ch = static_cast<char>(ch - 'A' + 'a');
            }
        }
        return ans;
    }
};

#endif //LEETCODE_831_H
