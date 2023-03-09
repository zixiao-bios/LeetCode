#ifndef LEETCODE_2379_H
#define LEETCODE_2379_H

class Solution {
public:
    int minimumRecolors(std::string blocks, int k) {
        int count = 0;
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'W') {
                ++count;
            }
        }
        int ans = count;
        for (int i = k; i < blocks.size(); ++i) {
            if (blocks[i] == 'W') {
                ++count;
            }
            if (blocks[i - k] == 'W') {
                --count;
            }
            ans = std::min(ans, count);
        }
        return ans;
    }
};

#endif //LEETCODE_2379_H
