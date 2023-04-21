#ifndef LEETCODE_2413_H
#define LEETCODE_2413_H

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 ? n * 2 : n;
    }
};

#endif //LEETCODE_2413_H
