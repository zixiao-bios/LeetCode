#ifndef LEETCODE_0077_H
#define LEETCODE_0077_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> num(k);
        backtracking(n, k, 1, 0, num, ans);
        return ans;
    }

    void backtracking(int n, int k, int np, int kp, vector<int> &num, vector<vector<int>> &ans) {
        if (kp == k) {
            ans.push_back(num);
            return;
        }

        for (int i = np; i <= n; ++i) {
            num[kp] = i;
            backtracking(n, k, i + 1, kp + 1, num, ans);
        }
    }
};

#endif //LEETCODE_0077_H
