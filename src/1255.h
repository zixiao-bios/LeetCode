#ifndef LEETCODE_1255_H
#define LEETCODE_1255_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> total, res;
    int n, ans = 0;

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        n = words.size();
        total = vector(26, 0);
        for (auto &each: letters) {
            ++total[each - 'a'];
        }

        backtrace(words, score, 0);
        return ans;
    }

    void backtrace(vector<string> &words, const vector<int> &score, int idx) {
        if (idx == n) {
            vector<int> count(26, 0);
            for (auto &each: res) {
                for (auto &ch: words[each]) {
                    ++count[ch - 'a'];
                }
            }

            int s = 0;
            for (int i = 0; i < 26; ++i) {
                s += score[i] * count[i];
                if (count[i] > total[i]) {
                    return;
                }
            }
            ans = max(ans, s);
            return;
        }

        res.push_back(idx);
        backtrace(words, score, idx + 1);
        res.erase(res.end() - 1);
        backtrace(words, score, idx + 1);
    }
};

#endif //LEETCODE_1255_H
