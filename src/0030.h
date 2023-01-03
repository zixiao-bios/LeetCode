#ifndef LEETCODE_0030_H
#define LEETCODE_0030_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> ans;
        int n = words[0].size();
        unordered_map<string, int> count_origin;
        for (auto &each: words) {
            ++count_origin[each];
        }

        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> count(count_origin);

            for (int left = i, right = i; right < s.size(); right += n) {
                string word = s.substr(right, n);
                --count[word];

                // 缩紧左边界
                while (count[word] < 0) {
                    ++count[s.substr(left, n)];
                    left += n;
                }

                if ((right - left) / n + 1 == words.size()) {
                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0030_H
