#ifndef LEETCODE_0771_H
#define LEETCODE_0771_H

#include <string>
#include <unordered_set>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        std::unordered_set<char> jew;
        for (const auto &each: jewels) {
            jew.insert(each);
        }

        int ans = 0;
        for (const auto &each: stones) {
            if (jew.find(each) != jew.end()) {
                ++ans;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0771_H
