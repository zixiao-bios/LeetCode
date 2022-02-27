#ifndef LEETCODE_MERGESORT_H
#define LEETCODE_MERGESORT_H

#include <vector>

using namespace std;

void mergeSort(vector<int> &nums, int start, int end) {
    if (end <= start) {
        return;
    }

    int mid = start + ((end - start) >> 1);

    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    vector<int> temp(end - start + 1);
    int a = start, b = mid + 1;

    for (int &i: temp) {
        if (a > mid or (b <= end and nums[b] < nums[a])) {
            i = nums[b++];
        } else {
            i = nums[a++];
        }
    }

    for (int i = 0; i < temp.size(); ++i) {
        nums[start + i] = temp[i];
    }
}

#endif //LEETCODE_MERGESORT_H
