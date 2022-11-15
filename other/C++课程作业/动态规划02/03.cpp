/**
 * 吃辣条大赛决赛

Description

Alice 进入了吃辣条大赛的决赛, 决赛的规则如下:

    桌子上从左到右摆放了两排辣条, 每一排辣条的数量均为 nn,每根辣条的长度不等.
    每个人可以从任意一根辣条开始吃, 但是不能连续吃同一排的辣条, 吃的顺序必须严格从左到右(即吃了第 11 排的第 ii 根, 则不能继续吃 第 22 排的第 ii 根, 只能从第 i+1i+1 根往右吃).
    吃到的辣条总长度最长的人获胜.

求 Alice 能吃到的辣条的最大总长度.

Input

输入包含三行,

第一行为一个正整数 n∈[1,100000]n∈[1,100000], 表示每一排辣条的数量.

第二行为 nn 个正整数 a1,⋯&ThinSpace;,an∈[1,109]a1​,⋯,an​∈[1,109],用空格隔开,从左到右表示第一排每根辣条的长度；第三行为 nn 个正整数 b1,⋯&ThinSpace;,bn∈[1,109]b1​,⋯,bn​∈[1,109], 用空格隔开, 从左到右表示第二排每根辣条的长度.

Output

输出 Alice 能吃到的辣条总长度的最大值.

Sample Input 1

3
1 2 9
10 1 1

Sample Output 1

19


 *
 *
* dp[a][i]: 只从第 a 排，索引为 [i,n-1] 中的辣条开始吃，能吃到的最大长度
 *
 * dp[0][i] = max(dp[1][i+1] + l[0][i], dp[0][i+1])
 *
 * dp[0][n-1] = l[0][n-1]
 *
 * dp[1][i] 同理
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> length(2, vector<int>(n));
    vector<vector<long long>> dp(2, vector<long long>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> length[i][j];
        }
    }

    dp[0][n - 1] = length[0][n - 1];
    dp[1][n - 1] = length[1][n - 1];

    for (int i = n - 2; i >= 0; --i) {
        dp[0][i] = max(dp[1][i + 1] + length[0][i], dp[0][i + 1]);
        dp[1][i] = max(dp[0][i + 1] + length[1][i], dp[1][i + 1]);
    }

    cout << max(dp[0][0], dp[1][0]);
}
