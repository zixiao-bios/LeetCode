#ifndef LEETCODE_0088_H
#define LEETCODE_0088_H

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m, --n;
        for (int i = int(nums1.size()) - 1; i >= 0; --i) {
            if (n < 0) {
                break;
            }

            if (m < 0) {
                while (n >= 0) {
                    nums1[i] = nums2[n];
                    --i, --n;
                }
                break;
            }

            if (nums1[m] >= nums2[n]) {
                nums1[i] = nums1[m];
                --m;
            } else {
                nums1[i] = nums2[n];
                --n;
            }
        }
    }
};

#endif //LEETCODE_0088_H
