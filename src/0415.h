#ifndef LEETCODE_0415_H
#define LEETCODE_0415_H

using std::string;

class Solution {
public:
    string addStrings(string num1, string num2) {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        string ans;
        bool flag = false;
        int p = 0;
        while (true) {
            if (p >= num1.size() and p >= num2.size()) {
                if (flag) {
                    ans += '1';
                }
                break;
            }

            int t = flag;
            if (p < num1.size()) {
                t += num1[p] - '0';
            }
            if (p < num2.size()) {
                t += num2[p] - '0';
            }
            ++p;

            flag = t / 10;
            t %= 10;
            ans += t + '0';
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODE_0415_H
