#ifndef LEETCODE_0074_H
#define LEETCODE_0074_H

#include <vector>

using namespace std;

class Solution {
public:
    int m, n, len;

    int get(const vector<vector<int>> &matrix, int idx) const {
        return matrix[idx / n][idx % n];
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        len = m * n;

        int left = 0, right = len - 1, mid;
        int val;
        while (left <= right) {
            mid = (left + right) / 2;
            val = get(matrix, mid);

            if (val == target) {
                return true;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

#endif //LEETCODE_0074_H
