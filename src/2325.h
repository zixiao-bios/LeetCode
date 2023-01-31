#ifndef LEETCODE_2325_H
#define LEETCODE_2325_H

#include <unordered_map>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> map;

        for (char ch: key) {
            if (ch != ' ' and map.find(ch) == map.end()) {
                map[ch] = 'a' + map.size();
            }
        }

        for (char &ch: message) {
            if (ch != ' ') {
                ch = map[ch];
            }
        }

        return message;
    }
};

#endif //LEETCODE_2325_H
