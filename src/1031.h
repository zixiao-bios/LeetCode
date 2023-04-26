#ifndef LEETCODE_1031_H
#define LEETCODE_1031_H

#include <vector>

using std::vector;

class Solution {
public:
    int n;

    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        n = static_cast<int>(nums.size());
        return std::max(two_sub_max_sum(nums, firstLen, secondLen),
                        two_sub_max_sum(nums, secondLen, firstLen));
    }

    int two_sub_max_sum(const vector<int> &nums, int left_len, int right_len) {
        int ans = 0;
        for (int ll = left_len; ll <= n; ++ll) {
            int rl = n - ll;
            if (rl < right_len) {
                break;
            }

            int sum = sub_max_sum(nums.cbegin(), nums.cbegin() + ll, left_len) +
                      sub_max_sum(nums.cbegin() + ll, nums.cend(), right_len);
            ans = std::max(ans, sum);
        }
        return ans;
    }

    int sub_max_sum(const vector<int>::const_iterator &begin, const vector<int>::const_iterator &end, int len) {
        int sum = 0;
        auto it = begin;
        for (int i = 0; i < len; ++i) {
            sum += *it;
            ++it;
        }

        int ans = sum;
        while (it != end) {
            sum += *it;
            sum -= *(it - len);
            ans = std::max(ans, sum);
            ++it;
        }
        return ans;
    }
};

#endif //LEETCODE_1031_H
