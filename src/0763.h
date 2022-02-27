#ifndef LEETCODE_0763_H
#define LEETCODE_0763_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPos(26);

        for (int i = 0; i < s.size(); ++i) {
            lastPos[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); ++i) {
            end = max(end, lastPos[s[i] - 'a']);

            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
                end = end + 1;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0763_H
