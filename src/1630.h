#ifndef LEETCODE_1630_H
#define LEETCODE_1630_H

#include <vector>
#include <unordered_set>

using std::vector;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        auto m = l.size();
        vector<bool> ans;

        for (int i = 0; i < m; ++i) {
            ans.push_back(is_arithmetic(nums.begin() + l[i], nums.begin() + r[i] + 1));
        }
        return ans;
    }

    static bool is_arithmetic(const vector<int>::iterator &begin, const vector<int>::iterator &end) {
        int max_num = *std::max_element(begin, end);
        int min_num = *std::min_element(begin, end);
        auto len = end - begin;

        if (len < 2) {
            return false;
        }
        if ((max_num - min_num) % (len - 1) != 0) {
            return false;
        }

        auto d = (max_num - min_num) / (len - 1);

        if (d == 0) {
            for (auto it = begin; it != end; ++it) {
                if (*it != min_num) {
                    return false;
                }
            }
        } else {
            std::unordered_set<int> set;
            for (auto it = begin; it != end; ++it) {
                if (set.find(*it) != set.end() or (*it - min_num) % d != 0) {
                    return false;
                } else {
                    set.insert(*it);
                }
            }
        }
        return true;
    }
};

#endif //LEETCODE_1630_H
