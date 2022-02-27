#ifndef LEETCODE_0605_H
#define LEETCODE_0605_H

#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int last = -1;

        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) {
                if (last == -1) {
                    count += i/2;
                } else {
                    count += (i - last - 2) / 2;
                }
                last = i;
            }
        }

        if (last == -1) {
            count += (flowerbed.size() + 1) / 2;
        } else {
            count += (flowerbed.size() - last - 1) / 2;
        }

        return count >= n;
    }
};

#endif //LEETCODE_0605_H
