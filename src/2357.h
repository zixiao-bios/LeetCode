#ifndef LEETCODE_2357_H
#define LEETCODE_2357_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        unordered_set<int> set;
        for (auto &each: nums) {
            if (each != 0) {
                set.insert(each);
            }
        }
        return set.size();
    }
};

#endif //LEETCODE_2357_H
