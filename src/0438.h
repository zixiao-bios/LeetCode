#ifndef LEETCODE_0438_H
#define LEETCODE_0438_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> count(26, 0);
        vector<int> ans;

        for (auto &ch: p) {
            ++count[ch - 'a'];
        }

        for (int l = 0, r = 0; r < s.size(); ++r) {
            --count[s[r] - 'a'];
            while (count[s[r] - 'a'] < 0) {
                ++count[s[l] - 'a'];
                ++l;
            }
            if (r - l + 1 == p.size()) {
                ans.push_back(l);
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0438_H
