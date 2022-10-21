#ifndef LEETCODE_0017_H
#define LEETCODE_0017_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> letter = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
                                   {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                   {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> ans;
        this->backtrack(digits, ans, "", 0);

        return ans;
    }

    void backtrack(const string &digits, vector<string> &ans, string combine, int level) {
        if (level == digits.size()) {
            ans.push_back(combine);
            return;
        }

        for (const auto &each:this->letter[digits[level] - '0']) {
            backtrack(digits, ans, combine + each, level + 1);
        }
    }
};

#endif //LEETCODE_0017_H
