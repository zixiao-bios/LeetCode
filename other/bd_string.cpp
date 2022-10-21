// https://www.cnblogs.com/chen9510/p/5515247.html

#include <iostream>
#include <vector>

using namespace std;

int max_n = 61;
vector<long long> len(max_n, 0);

// 计算前 x 个子母中，B 的个数
long long get_b_num(long long x) {
    if (x <= 0) {
        return 0;
    }
    if (x == 1) {
        return 1;
    }

    int i = lower_bound(len.begin(), len.end(), x) - len.begin();

    if (len[i] == x) {
        return len[i] / 2 + 1;
    }

    // len[i-1] < x < len[i]
    return x - len[i - 1] + get_b_num(len[i] - x);
}

int main() {
    len[1] = 1;
    for (int i = 2; i < max_n; ++i) {
        len[i] = 2 * len[i - 1] + 1;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << get_b_num(b) - get_b_num(a - 1) << endl;
    }
}
