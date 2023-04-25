#ifndef LEETCODE_2418_H
#define LEETCODE_2418_H

#include <vector>
#include <algorithm>

using std::vector, std::string;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = static_cast<int>(names.size());

        vector<int> idx(n);
        for (int i = 0; i < n; ++i) {
            idx[i] = i;
        }

        std::sort(idx.begin(), idx.end(), [&](int a, int b) { return heights[a] > heights[b]; });

        vector<string> ans;
        ans.reserve(n);
        for (int i = 0; i < n; ++i) {
            ans.push_back(names[idx[i]]);
        }
        return ans;
    }
};

#endif //LEETCODE_2418_H
