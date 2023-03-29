#ifndef LEETCODE_1641_H
#define LEETCODE_1641_H

class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};

#endif //LEETCODE_1641_H
