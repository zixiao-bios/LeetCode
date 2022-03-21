#ifndef LEETCODE_0022_H
#define LEETCODE_0022_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

    static void backtrack(vector<string> &ans, string cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }

        if (open < n) {
            cur += '(';
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }

        if (close < open) {
            cur += ')';
            backtrack(ans, cur, open, close + 1, n);
        }
    }
};

#endif //LEETCODE_0022_H
