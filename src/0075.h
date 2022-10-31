/**
 * 将输入数组分为 3 段，从左到右分别为：0段、混合段、1段
 * 指针 l, r 分别指向未处理段的两端，p 用于遍历数组
 * 初始时 l=0, r=size()-1, p=l
 *
 * 若 a[p]=0，则交换 a[p], a[l], l++
 * 若 a[p]=2，则交换 a[p], a[r], r--
 * 若 a[p]=1，则 p++
 * 直到 p>r，此时混合段中全为 1
 */

#ifndef LEETCODE_0075_H
#define LEETCODE_0075_H

#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int p = l;

        while (p <= r and l < nums.size() and r >= 0) {
            switch (nums[p]) {
                case 0:
                    swap(nums[p], nums[l]);
                    ++l;
                    p = max(p, l);
                    break;
                case 2:
                    swap(nums[p], nums[r]);
                    --r;
                    break;
                case 1:
                    ++p;
            }
        }
    }
};

#endif //LEETCODE_0075_H
