#ifndef LEETCODE_0763_H
#define LEETCODE_0763_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_idx;

        for (int i = 0; i < s.size(); ++i) {
            last_idx[s[i]] = i;
        }

        vector<int> len_list;
        int start = 0, end = -1;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, last_idx[s[i]]);
            if (i == end) {
                // 当前片段结束
                len_list.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return len_list;
    }
};

#endif //LEETCODE_0763_H
