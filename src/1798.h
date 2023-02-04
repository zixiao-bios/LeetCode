#ifndef LEETCODE_1798_H
#define LEETCODE_1798_H

/**
 * 假设当前硬币集合能构造的数为[0, x]，新加入一个硬币，值为y
 * 则新的能构造的数的集合为[y, x+y]
 * 如果 y <= x+1 ，则这两个区间能连起来，新的区间为[0, x+y]
 * 否则，新的区间仍为[0, x]
 * 为了让区间尽可能的大，y需要尽可能的小，因此先将序列按升序排序
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    int getMaximumConsecutive(std::vector<int> &coins) {
        std::sort(coins.begin(), coins.end());

        int x = 0;
        for (int coin : coins) {
            if (coin <= x + 1) {
                x += coin;
            } else {
                break;
            }
        }

        return x + 1;
    }
};

#endif //LEETCODE_1798_H
