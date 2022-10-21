/**
字符串排序

Description

给定一组字符串, 现在希望把这一组字符串调整为按字典序排列的情形.

要求: 不能变换字符串的相对位置, 只能对某些字符串进行反转操作.

反转一个字符串有一定的消耗(设为 cic_ici​), 求一个方案使得最终总的消耗最小, 输出最小的消耗.

Input

输入的第一行为一个正整数 n∈[2,100000]n \in [2,100000]n∈[2,100000] 表示改组字符串的个数.

第二行为 nnn 个整数 ci∈[0,109]c_i \in [0,10^9]ci​∈[0,109], 表示反转第 iii 个字符串的开销.

接下来 nnn 行, 每一行为一个字符串, 字符串长度不超过 100000100000100000.

Output

输出最小的总开销, 如果不存在可行的方案使得这组字符串按字典序排列, 则输出 "−1-1−1".

Sample Input 1

2
1 2
ba
ac

Sample Output 1

1

Sample Input 2

2
5 5
bbb
aaa

Sample Output 2

-1

Sample Input 3

4
0 0 8 6
bi
qp
bt
ya

Sample Output 3

8
 */

/**
 * dp[i][j]：只考虑从下标为 0~i 的字符串，且下标为 i 的字符串的反转状态为 j 时，满足字典序的最小消耗
 *
 * dp[i][0] = dp[i-1][0]        , s[i] < reverse(s[i-1]) and s[i] >= s[i-1]
 *            dp[i-1][1]        , s[i] < s[i-1] and s[i] >= reverse(s[i-1])
 *            min(dp[i-1][j])   , s[i] >= s[i-1] and s[i] >= reverse(s[i-1])
 *            MAX               , else
 *
 * dp[i][1] = dp[i-1][0] + c[i]         , reverse(s[i]) < reverse(s[i-1]) and reverse(s[i]) >= s[i-1]
 *            dp[i-1][1] + c[i]         , reverse(s[i]) < s[i-1] and reverse(s[i]) >= reverse(s[i-1])
 *            min(dp[i-1][j]) + c[i]    , reverse(s[i]) >= s[i-1] and reverse(s[i]) >= reverse(s[i-1])
 *            MAX                       , else
 * 上述加法应避免溢出：MAX + c[i] = MAX
 *
 * dp[0][0] = 0
 * dp[0][1] = c[0]
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long add(long long a, long long b) {
    if (a == LONG_LONG_MAX or b == LONG_LONG_MAX) {
        return LONG_LONG_MAX;
    } else {
        return a + b;
    }
}

int main() {
    int n;
    cin >> n;

    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(2));
    dp[0][0] = 0;
    dp[0][1] = c[0];

    string si = s[0];
    string si_rev(si);
    reverse(si_rev.begin(), si_rev.end());
    string si_1, si_1_rev;
    for (int i = 1; i < n; ++i) {
        si_1 = si;
        si_1_rev = si_rev;
        si = s[i];
        si_rev = string(si);
        reverse(si_rev.begin(), si_rev.end());

        if (si < si_1_rev and si >= si_1) {
            dp[i][0] = dp[i - 1][0];
        } else if (si < si_1 and si >= si_1_rev) {
            dp[i][0] = dp[i - 1][1];
        } else if (si >= si_1 and si >= si_1_rev) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
        } else {
            dp[i][0] = LONG_LONG_MAX;
        }

        if (si_rev < si_1_rev and si_rev >= si_1) {
            dp[i][1] = add(dp[i - 1][0], c[i]);
        } else if (si_rev < si_1 and si_rev >= si_1_rev) {
            dp[i][1] = add(dp[i - 1][1], c[i]);
        } else if (si_rev >= si_1 and si_rev >= si_1_rev) {
            dp[i][1] = add(min(dp[i - 1][0], dp[i - 1][1]), c[i]);
        } else {
            dp[i][1] = LONG_LONG_MAX;
        }
    }

    if (dp[n - 1][0] == LONG_LONG_MAX and dp[n - 1][1] == LONG_LONG_MAX) {
        cout << -1;
    } else {
        cout << min(dp[n - 1][0], dp[n - 1][1]);
    }
}
