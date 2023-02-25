#ifndef LEETCODE_1247_H
#define LEETCODE_1247_H

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return -1;
        }

        int xy = 0, yx = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == 'x' and s2[i] == 'y') {
                ++xy;
            } else if (s1[i] == 'y' and s2[i] == 'x') {
                ++yx;
            }
        }

        if ((xy + yx) % 2 != 0) {
            return -1;
        }

        return xy / 2 + yx / 2 + 2 * (xy % 2);
    }
};

#endif //LEETCODE_1247_H
