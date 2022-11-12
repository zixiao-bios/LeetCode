/**
 * 打野

Description

在 Dota 游戏中, 英雄通过击败野外的怪物(简称野怪)可以获取一定量的金币, 但是在此过程中也会损失一定量的生命值.

现在一位名为奈文摩尔的英雄希望通过击败野怪来获取金币, 假设他的初始生命值为 RR, 在保证英雄不被野怪击败(即 R≥0R≥0)的情况下, 求该英雄最多可以获取多少金币.

Input

输入包含三行, 第一行为两个正整数 N,R∈[1,1000]N,R∈[1,1000] 分别表示野怪的数量以及奈文摩尔的初始生命值.

第二行包含 NN 个正整数, 表示击败每个野怪可以得到的金币,

第三行包含 NN 个正整数, 表示击败每个野怪需要消耗的生命值.

Output

输出单独一行, 表示奈文摩尔可以得到的最大金币数.

(假设击败野怪的过程中生命值不会恢复)

Sample Input 1

5 14
8 2 2 2 8
7 8 4 5 3

Sample Output 1

18


 *
 *
 *
 * dp[i][j]: 只考虑到索引为 i 的怪物，且生命值为 j 时的最大金币数
 *
 * dp[i][j] =   max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]) , j >= w[i]
 *              dp[i-1][j]                              , j < w[i]
 *
 * dp[0][j] = v[0]  , j >= w[0]
 *            0     , j < w[0]
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<int> v(n), w(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<vector<int>> dp(n, vector<int>(r + 1));

    for (int j = 0; j < r + 1; ++j) {
        if (j < w[0]) {
            dp[0][j] = 0;
        } else {
            dp[0][j] = v[0];
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < r + 1; ++j) {
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n - 1][r] << endl;
}
