#ifndef LEETCODE_0455_H
#define LEETCODE_0455_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;

        while (child < g.size() and cookie < s.size()) {
            if (g[child] <= s[cookie]) {
                ++child;
            }
            ++cookie;
        }

        return child;
    }
};

#endif //LEETCODE_0455_H
