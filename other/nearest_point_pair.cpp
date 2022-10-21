#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

double distance(const vector<int> &a, const vector<int> &b) {
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
}

double find_min(const vector<vector<int>> &data, int left, int right) {
    if (right - left < 1) {
        return 1e100;
    }

    if (right - left == 1) {
        return distance(data[left], data[right]);
    }

    int mid_idx = (left + right) / 2;
    int lr = mid_idx, rl = mid_idx + 1;
    double min_dis = min(find_min(data, left, lr), find_min(data, rl, right));
    double mid_x = (data[lr][0] + data[rl][0]) / 2.;

    int ll = lr;
    while (ll > left and mid_x - data[ll][0] < min_dis) {
        --ll;
    }

    int rr = rl;
    while (rr < right and data[rr][0] - mid_x < min_dis) {
        ++rr;
    }

    vector<vector<int>> right_y(data.begin() + rl, data.begin() + rr + 1);
    vector<vector<int>> left_y(data.begin() + ll, data.begin() + lr + 1);
    sort(right_y.begin(), right_y.end(), [](vector<int> &a, vector<int> &b) { return a[1] > b[1]; });
    sort(left_y.begin(), left_y.end(), [](vector<int> &a, vector<int> &b) { return a[1] > b[1]; });

    int right_top_idx = 0, left_idx = 0;
    while (true) {
        while (left_idx < left_y.size() and left_y[left_idx][1] - right_y[right_top_idx][1] > min_dis) {
            ++left_idx;
        }
        if (left_idx > left_y.size() - 1) {
            break;
        }

        while (right_top_idx < right_y.size() and right_y[right_top_idx][1] - left_y[left_idx][1] > min_dis) {
            ++right_top_idx;
        }
        if (right_top_idx > right_y.size() - 1) {
            break;
        }

        for (int i = right_top_idx; i < right_y.size(); ++i) {
            if (left_y[left_idx][1] - right_y[i][1] > min_dis) {
                break;
            }

            if (right_y[i][0] - left_y[left_idx][0] <= min_dis) {
                min_dis = min(min_dis, distance(left_y[left_idx], right_y[i]));
            }
        }
        ++left_idx;
    }

    return min_dis;
}

int main() {
    int n;
    cin >> n;

    int x, y;
    vector<vector<int>> data(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        data[i][0] = x;
        data[i][1] = y;
    }

    sort(data.begin(), data.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

    double min = find_min(data, 0, n - 1);
    if (min >= 10000) {
        cout << "INFINITY";
    } else {
        cout << fixed << setprecision(4) << min;
    }
}
