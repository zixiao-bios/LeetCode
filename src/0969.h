#ifndef LEETCODE_969_H
#define LEETCODE_969_H

/// 煎饼排序

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        vector<int>::reverse_iterator max;

        for (auto i = arr.rbegin(); i != arr.rend(); ++i) {
            max = max_element(i, arr.rend());
            if (*i == *max) {
                continue;
            }

            reverse(max, arr.rend());
            ans.push_back(distance(max, arr.rend()));

            reverse(i, arr.rend());
            ans.push_back(distance(i, arr.rend()));
        }

        return ans;
    }
};

#endif //LEETCODE_969_H
