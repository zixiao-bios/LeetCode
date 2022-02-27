#ifndef LEETCODE_QUICKSORT_H
#define LEETCODE_QUICKSORT_H

#include <vector>

using namespace std;

void quickSort(vector<int> &nums, int start, int end) {
    if (end <= start) {
        return;
    }

    int l = start, r = end, key = nums[l];

    while (l < r) {
        while (l < r and nums[r] >= key) {
            --r;
        }
        nums[l] = nums[r];

        while (l < r and nums[l] <= key) {
            ++l;
        }
        nums[r] = nums[l];
    }

    nums[r] = key;
    quickSort(nums, start, r - 1);
    quickSort(nums, r + 1, end);
}

#endif //LEETCODE_QUICKSORT_H
