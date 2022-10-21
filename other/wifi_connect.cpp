/**
Description

假设手机在连接 WiFi 时总是连接最近的路由器, 因此拿着手机移动时, 随着与每个路由器距离的变化会进行路由器(相同SSID)连接的转换.

畅春园宿舍楼的每一间宿舍都安装了一个路由器, 路由器安装的具体位置不固定, Alice 拿着手机在宿舍楼附近移动, 现在他想知道移动的过程中共进行了多少次路由器连接的转换.

为了简化问题, 现在假设 Alice 每次选择一个起点和一个终点, 移动的路线为直线.

Input

输入的第一行为两个正整数 n,m(n∈[3,50],m∈[2,50])n, m (n\in [3,50], m\in [2,50])n,m(n∈[3,50],m∈[2,50]), nnn 表示 Alice 移动的可能起点或终点的坐标个数, mmm 表示宿舍楼安装的路由器个数.

随后 nnn 行, 每一行两个整数 x,y∈[0,1000]x, y \in [0,1000]x,y∈[0,1000], 表示起点或终点的坐标.

接下来 mmm 行,每一行两个整数 x,y∈[0,1000]x, y \in [0,1000]x,y∈[0,1000], 表示路由器位置的坐标.

接下来一行为一个整数 kkk, 表示 Alice 实验的次数.

后续 kkk 行, 每一行两个正整数 a,b∈[1,n]a, b \in [1, n]a,b∈[1,n], aaa 表示起点坐标的序号, bbb 表示终点坐标的序号. (序号指的是前面输入起点和终点坐标的顺序)

Output

对于 Alice 的每次实验, 输出单独的一行, 表示实验过程中路由器连接转换的次数.
**/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

double resolution = 1;

// 返回两点的欧氏距离
double distance(const pair<double, double> &a, const pair<double, double> &b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

// 返回位于 pos 时，连接到的路由器 index
int connect_router(const vector<pair<double, double>> &router_list, const pair<double, double> &pos) {
    double min_dis = numeric_limits<double>::max();
    int router_idx = -1;

    for (int i = 0; i < router_list.size(); ++i) {
        double dis = distance(pos, router_list[i]);
        if (dis < min_dis) {
            router_idx = i;
            min_dis = dis;
        }
    }

    return router_idx;
}

// 返回从 start 走到 end 中，路由器连接转换的次数
int connect_num(const vector<pair<double, double>> &router_list, const pair<double, double> &start, const pair<double, double> &end) {
    if (connect_router(router_list, start) == connect_router(router_list, end)) {
        return 0;
    }

    // 起点和终点不在一个路由器下

    // 起点和终点距离小于分辨率，则认为只转换了 1 次
    if (distance(start, end) <= resolution) {
        return 1;
    }

    pair<double, double> mid;
    mid.first = (start.first + end.first) / 2;
    mid.second = (start.second + end.second) / 2;

    return connect_num(router_list, start, mid) + connect_num(router_list, mid, end);
}

int main() {
    int pos_num, router_num;
    cin >> pos_num >> router_num;

    vector<pair<double, double>> pos_list(pos_num);
    for (int i = 0; i < pos_num; ++i) {
        cin >> pos_list[i].first >> pos_list[i].second;
    }

    vector<pair<double, double>> router_list(router_num);
    for (int i = 0; i < router_num; ++i) {
        cin >> router_list[i].first >> router_list[i].second;
    }

    int walk_num;
    cin >> walk_num;
    for (int i = 0; i < walk_num; ++i) {
        int a, b;
        cin >> a >> b;
        cout << connect_num(router_list, pos_list[a - 1], pos_list[b - 1]) << endl;
    }
}
