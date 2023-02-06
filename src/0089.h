#ifndef LEETCODE_0089_H
#define LEETCODE_0089_H

#include <vector>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        int size = 1 << n;
        std::vector<int> ans(size, 0);

        int prefix = 1;
        for (int i = 1; i <= n; ++i) {
            int done_num = 1 << (i - 1);
            for (int j = done_num - 1; j >= 0; --j) {
                ans[done_num + done_num - 1 - j] = prefix + ans[j];
            }
            prefix <<= 1;
        }

        return ans;
    }
};

#endif //LEETCODE_0089_H
