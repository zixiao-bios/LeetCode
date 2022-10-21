/**
Alice 的烦恼

Description

Alice 是某大厂的程序员, 由于年龄到了35岁面临被裁员, 他准备去广场摆摊卖烤冷面. 为了控制成本, Alice 买了 nnn 根散装火腿肠作为重要原料. 这就带来了一个问题, 由于生产流程不够标准化, 火腿肠的长度各不相同.

为了保证买卖公平, 明码标价, 现在 Alice 准备把这些火腿肠切成等长的 mmm 份, 为了保证口感, 他还同时希望每一份的长度越长越好, 你能写出一个算法帮他算出每一份的最大长度吗?

Input

输入的第一行为两个正整数 n,m∈[1,10000]n, m \in [1,10000]n,m∈[1,10000], 分别代表火腿肠的总数以及 Alice 要切的份数.

后面 nnn 行, 每一行为一个浮点数, 表示火腿肠的长度.

Output

输出切分后的火腿肠的最大长度, 结果保留两位小数(如果最终切分的结果小于 0.010.010.01, 输出 0.000.000.00 表示创业失败).

Sample Input 1

5 10
11.16
76.45
98.51
5.79
60.96

Sample Output 1

20.32
**/

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iomanip>
//#include <numeric>
//#include <cmath>
//
//using namespace std;
//
//int n, m;
//
//int get_max_num(const vector<double> &lens, int right, double len) {
//    int num = 0;
//    for (int i = 0; i <= right; ++i) {
//        num += int(lens[i] / len);
//    }
//    return num;
//}
//
//double find_max_len(const vector<double> &lens, int right, int j, int j_min_num, int j_max_num) {
//    if (j_min_num > j_max_num) {
//        return -1;
//    }
//
//    int j_mid_num = (j_min_num + j_max_num) / 2;
//    double len = lens[j] / j_mid_num;
//
//    if (get_max_num(lens, right, len) >= m) {
//        return max(len, find_max_len(lens, right, j, j_min_num, j_mid_num - 1));
//    } else {
//        return find_max_len(lens, right, j, j_mid_num + 1, j_max_num);
//    }
//}
//
//int main() {
//    cin >> n >> m;
//
//    vector<double> lens(n);
//    for (int i = 0; i < n; ++i) {
//        scanf("%lf", &lens[i]);
//    }
//
//    sort(lens.begin(), lens.end(), [](double &len1, double &len2) { return len1 > len2; });
//
//    double max_len = lens[0] / m;
//    for (int i = 1; i < n; ++i) {
//        if (lens[i] <= max_len) {
//            break;
//        }
//
//        // 加入下一根火腿，尝试寻找更大长度
//        for (int j = 0; j <= i; ++j) {
//            // 假设 j 火腿全部被利用
//            int j_max_num = int(lens[j] / max_len);
//            int j_min_num = ceil(lens[j] / (accumulate(lens.begin(), lens.begin() + j + 1, 0.) / m));
//
//            // 二分搜索 j 的切段数，找到满足 m 的最大长度
//            max_len = max(max_len, find_max_len(lens, i, j, j_min_num, j_max_num));
//        }
//    }
//
//    if (max_len < 0.01) {
//        cout << "0.00";
//    } else {
//        cout << fixed << setprecision(2) << int(max_len * 100) / 100.;
//    }
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <cmath>

using namespace std;

int n, m;
double precision = 1e-3;

int get_max_num(const vector<double> &lens, double len) {
    int num = 0;
    for (int i = 0; i <= n; ++i) {
        num += int(lens[i] / len);
    }
    return num;
}

double find_max_len(const vector<double> &lens, double start, double end) {
    if (end - start <= precision) {
        return end;
    }

    double mid = (start + end) / 2;

    if (get_max_num(lens, mid) >= m) {
        return find_max_len(lens, mid, end);
    } else {
        return find_max_len(lens, start, mid);
    }
}

int main() {
    cin >> n >> m;

    vector<double> lens(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &lens[i]);
    }

    sort(lens.begin(), lens.end(), [](double &len1, double &len2) { return len1 > len2; });

    double min_len = lens[0] / m;
    double max_len = accumulate(lens.begin(), lens.end(), 0.) / m;

    double ans = find_max_len(lens, min_len, max_len);

    if (ans < 0.01) {
        cout << "0.00";
    } else {
        cout << fixed << setprecision(2) << int(ans * 100) / 100.;
    }
}
