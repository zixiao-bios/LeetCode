#ifndef LEETCODE_1590_H
#define LEETCODE_1590_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int> &nums, int p) {
        int n = nums.size();
        vector<int> prefix_sum(n + 1, 0);

        for (int i = 1; i < n + 1; ++i) {
            prefix_sum[i] = (prefix_sum[i - 1] + nums[i - 1]) % p;
        }

        // 前缀和的两元素之差，与p求余后，要等于target
        int target = *(prefix_sum.rbegin()) % p;
        if (target == 0) {
            return 0;
        }

        int ans = n;
        unordered_map<int, int> map;

        for (int i = 0; i < n + 1; ++i) {
            // (a-b) % p == target
            // k1 * p + target == a - b
            // a == k1 * p + target + b == k1*p + (target+b)%p + k2*p == (k1+k2)*p + (target+b)%p
            // a % p == (target + b) % p
            if (map.find(prefix_sum[i] % p) != map.end()) {
                ans = min(ans, i - map[prefix_sum[i] % p]);
            }
            map[(prefix_sum[i] + target) % p] = i;
        }

        return ans == n ? -1 : ans;
    }
};

#endif //LEETCODE_1590_H
