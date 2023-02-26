#ifndef LEETCODE_1255_2_H
#define LEETCODE_1255_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        vector<int> total(26, 0);
        for (auto &each: letters) {
            ++total[each - 'a'];
        }

        int ans = 0;
        for (int state = 0; state < 1 << words.size(); ++state) {
            vector<int> count(26, 0);
            for (int i = 0; i < words.size(); ++i) {
                if (1 << i & state) {
                    for (auto &c: words[i]) {
                        ++count[c - 'a'];
                    }
                }
            }

            bool ok = true;
            int s = 0;
            for (int i = 0; i < 26; ++i) {
                s += count[i] * score[i];
                if (count[i] > total[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans = max(ans, s);
            }
        }

        return ans;
    }
};

#endif //LEETCODE_1255_2_H
