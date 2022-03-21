#ifndef LEETCODE_0006_H
#define LEETCODE_0006_H

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string ans;
        int t = numRows * 2 - 2;
        int n;

        // 第一行
        n = 0;
        while (true) {
            if (n * t >= s.size())
                break;
            ans += s[n * t];
            ++n;
        }

        // 中间行
        for (int i = 1; i < numRows - 1; ++i) {
            n = 0;
            while (true) {
                if (n * t + i >= s.size())
                    break;
                ans += s[n * t + i];
                ++n;

                if (n * t - i >= s.size())
                    break;
                ans += s[n * t - i];
            }
        }

        // 最后一行
        n = 0;
        while (true) {
            if (n * t + numRows - 1 >= s.size())
                break;

            ans += s[n * t + numRows - 1];
            ++n;
        }

        return ans;
    }
};

#endif //LEETCODE_0006_H
