/**
 * 找到合并后的索引为 (m+n)/2 和 (m+n-1)/2 的值
 * 转化为寻找第 k 大的数
 *
 * 若 a[k/2-1] < b[k/2-1]
 * 则 a[k/2-1] 前面最多有 k-2 个数，即 a[k/2-1] 最多为第 k-1 大的数
 * 因此可把 a[k/2-1] 和其之前的数排除，并将 k 减去相应的量
 */

#ifndef LEETCODE_0004_H
#define LEETCODE_0004_H

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int findKth(const vector<int> &a, const vector<int> &b, int a_offset, int b_offset, int k) {
        if (a_offset >= a.size()) {
            return b[b_offset + k - 1];
        }
        if (b_offset >= b.size()) {
            return a[a_offset + k - 1];
        }
        if (k == 1) {
            return min(a[a_offset], b[b_offset]);
        }

        int mid = k / 2 - 1;
        int a_mid = min(mid, (int)a.size() - a_offset - 1);
        int b_mid = min(mid, (int)b.size() - b_offset - 1);

        if (a[a_offset + a_mid] < b[b_offset + b_mid]) {
            return findKth(a, b, a_offset + a_mid + 1, b_offset, k - a_mid - 1);
        } else {
            return findKth(a, b, a_offset, b_offset + b_mid + 1, k - b_mid - 1);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i1 = int(nums1.size() + nums2.size()) / 2;
        int i2 = int(nums1.size() + nums2.size() - 1) / 2;
        return double(findKth(nums1, nums2, 0, 0, i1 + 1) + findKth(nums1, nums2, 0, 0, i2 + 1)) / 2;
    }
};

#endif //LEETCODE_0004_H
