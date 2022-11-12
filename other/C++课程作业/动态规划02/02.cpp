/**
 * 吃辣条大赛

Description

Alice 参加了学院近期举办的吃辣条大赛, 桌子上摆放了若干根辣条, 每根辣条的长度不等, 要求只能按从左到右长度严格递增的顺序吃, 每位参赛选手有一次机会扔掉其中的一根辣条(也可以不扔).

给出从左到右排列的每根辣条的长度, 请问 Alice 最多可以吃到多少根辣条.

Input

输入包含两行, 第一行为一个正整数 n∈[2,200000]n∈[2,200000], 表示辣条的总数.

第二行为 nn 个正整数 l1,⋯&ThinSpace;,lnl1​,⋯,ln​, 用空格分隔, 表示每根辣条的长度 li∈[1,109]li​∈[1,109].

Output

输出单独一行, 表示 Alice 能吃到的辣条的最大数量.

Sample Input 1

6
2 3 8 4 5 7

Sample Output 1

5

Hint

在测试样例中, 可以扔掉第三根辣条, 得到 `2 3 4 5 7`, 因此最终可以吃到 5 根.


 *
 *
 *
 * dp[i][1]: 从索引为 i 的辣条开始吃，能吃的最大根数（能扔掉一根辣条）
 * dp[i][0]: 从索引为 i 的辣条开始吃，能吃的最大根数（不能扔辣条）
 *
 *
 * 从后往前遍历
 * dp[i][1] = max(dp[i+1][1] + 1, dp[i+2][0] + 1, 1)    , 条件各自独立判断
 * dp[i][0] = max(dp[i+1][0] + 1, 1)                    , 条件各自独立判断
 *
 *
 * dp[n-1][1] = dp[n-1][0] = 1
 *
 * dp[n-2][1] = dp[n-2][0] = 2  , l[n-2] < l[n-1]
 *                         = 1  , else
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, 1));
    dp[n - 1][0] = 1;
    dp[n - 1][1] = 1;
    if (l[n - 2] < l[n - 1]) {
        dp[n - 2][0] = 2;
        dp[n - 2][1] = 2;
    } else {
        dp[n - 2][0] = 1;
        dp[n - 2][1] = 1;
    }

    for (int i = n - 3; i >= 0; --i) {
        if (l[i] < l[i + 1]) {
            dp[i][1] = max(dp[i][1], dp[i + 1][1] + 1);
            dp[i][0] = max(dp[i][0], dp[i + 1][0] + 1);
        }

        if (l[i] < l[i + 2]) {
            dp[i][1] = max(dp[i][1], dp[i + 2][0] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i][1]);
    }

    cout << ans << endl;
}
