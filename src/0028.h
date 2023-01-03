#ifndef LEETCODE_0028_H
#define LEETCODE_0028_H

#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.find(needle);
        return n == string::npos ? -1 : n;
    }
};

#endif //LEETCODE_0028_H
