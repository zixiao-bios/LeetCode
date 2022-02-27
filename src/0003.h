#ifndef LEETCODE_0003_H
#define LEETCODE_0003_H

#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int max = 0;
        unordered_map<char, int> map;
        unordered_map<char, int>::iterator lastSameChar;

        for (int end = 0; end < s.length(); ++end) {
            lastSameChar = map.find(s[end]);
            if (lastSameChar != map.end()) {
                // this substring contains repeating char
                start = std::max(start, lastSameChar->second + 1);
            }

            max = std::max(max, end - start + 1);
            map[s[end]] = end;
        }

        return max;
    }
};

#endif //LEETCODE_0003_H
