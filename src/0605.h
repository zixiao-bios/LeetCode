#ifndef LEETCODE_0605_H
#define LEETCODE_0605_H

#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        int left = 0, right = 0;
        int max_num = 0;

        while (true) {
            left = right;
            while (left < flowerbed.size() and flowerbed[left] == 1) {
                ++left;
            }
            if (left == flowerbed.size()) {
                break;
            }

            right = left;
            while (right < flowerbed.size() and flowerbed[right] == 0) {
                ++right;
            }
            if (right == flowerbed.size()) {
                max_num += (flowerbed.size() - left - 1) / 2;
                break;
            }

            max_num += (right - left - 1) / 2;
        }

        return max_num >= n;
    }
};

#endif //LEETCODE_0605_H
