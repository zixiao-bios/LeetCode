/**
小朋友才做选择

Description

Alice 小朋友参加商场的促销游戏, 现有 nnn 个糖果堆, Alice 要完成一个游戏, 每次从这 nnn 个糖果堆中选择其中的一个, 直到拿完所有的糖果堆.

假设选择的这一个有 xxx 个糖果, 则需要从剩下的所有糖果堆中移除糖果数量为 x−1x-1x−1 以及 x+1x+1x+1 的糖果堆.

问 Alice 小朋友最多能拿到多少数量的糖果.

Input

输入的第一行为一个正整数 n∈[1,100000]n\in [1,100000]n∈[1,100000], 表示糖果堆的个数.

第二行为 nnn 个正整数, 每一个正整数 xi∈[1,100000]x_i \in [1,100000]xi​∈[1,100000] 表示当前糖果堆中糖果的数量.

Output

输出单独一行, 表示 Alice 最多能获得的糖果数量.

Sample Input 1

10
1 1 1 1 1 1 2 3 4 4

Sample Output 1

14

Sample Input 2

5
5 3 5 3 4

Sample Output 2

16

Hint

如第二组样例，先拿 3，去掉 2, 4(序列中没有 2), 还剩下 5 5 3，再拿 5，去掉 4, 6(剩下序列中都没有), 还剩下 5 3, 一次类推, 最大值为 3 + 5 + 5 + 3 = 16

 */

/**
 * dp[i][j]：只考虑到索引为 i 的糖果堆，且其中最后一堆的选择为 j 时，最大糖果数
 *
 * dp[i][j] = dp[i-1][j]    (value[i] == value[i-1])
 *
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1])
 *
 * dp[i][1] = dp[i][0] + value[i]                       (value[i] - value[i-1] == 1)
 *            max(dp[i-1][0], dp[i-1][1]) + value[i]    (value[i] - value[i-1] != 1)
 *
 * dp[0][0] = 0
 * dp[0][1] = value[0]
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void print_track(const vector<vector<int>> &track, int last) {
    vector<int> ans(track.size());

    for (int i = track.size() - 1; i >= 0; --i) {
        ans[i] = last;
        last = track[i][last];
    }

    for (int i = 0; i < track.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> value(n);
    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }
    sort(value.begin(), value.end());

    vector<vector<int>> dp(n, vector<int>(2));
    vector<vector<int>> track(n, vector<int>(2));
    /// track[i][j]：索引为 i 的糖堆选择情况为 j 时，索引为 i-1 的糖堆的选择情况
    dp[0][0] = 0;
    dp[0][1] = value[0];

    for (int i = 1; i < n; ++i) {
        if (value[i] == value[i - 1]) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + value[i];
            track[i][0] = 0;
            track[i][1] = 1;
            continue;
        }

        if (dp[i - 1][0] > dp[i - 1][1]) {
            dp[i][0] = dp[i - 1][0];
            track[i][0] = 0;
        } else {
            dp[i][0] = dp[i - 1][1];
            track[i][0] = 1;
        }

        if (value[i] - value[i - 1] == 1) {
            dp[i][1] = dp[i - 1][0] + value[i];
            track[i][1] = 0;
        } else {
            if (dp[i - 1][0] > dp[i - 1][1]) {
                dp[i][1] = dp[i - 1][0] + value[i];
                track[i][1] = 0;
            } else {
                dp[i][1] = dp[i - 1][1] + value[i];
                track[i][1] = 1;
            }
        }
    }

//    if (dp[n - 1][0] > dp[n - 1][1]) {
//        print_track(track, 0);
//        cout << dp[n - 1][0];
//    } else {
//        print_track(track, 1);
//        cout << dp[n - 1][1];
//    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
}
