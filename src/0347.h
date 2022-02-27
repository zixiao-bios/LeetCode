#ifndef LEETCODE_0347_H
#define LEETCODE_0347_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> countMap;

        for (auto &num: nums) {
            ++countMap[num];
        }

        vector<pair<int, int>> count(countMap.size());
        for (auto &each: countMap) {
            count.emplace_back(each);
        }

        int l = 0, r = count.size() - 1, index;
        while (l <= r) {
            index = quickSelection(count, l, r);

            if (index + 1 == k) {
                vector<int> ans(k);
                for (int i = 0; i < k; ++i) {
                    ans[i] = count[i].first;
                }
                return ans;
            } else if (index + 1 > k) {
                r = index - 1;
            } else {
                l = index + 1;
            }
        }

        return {};
    }

    int quickSelection(vector<pair<int, int>> &count, int start, int end) {
        int l = start, r = end;
        pair<int, int> key = count[l];

        while (l < r) {
            while (l < r and count[r].second <= key.second) {
                --r;
            }
            count[l] = count[r];

            while (l < r and count[l].second >= key.second) {
                ++l;
            }
            count[r] = count[l];
        }

        count[r] = key;
        return r;
    }
};

#endif //LEETCODE_0347_H
