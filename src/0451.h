#ifndef LEETCODE_0451_H
#define LEETCODE_0451_H

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void quickSort(vector<pair<char, int>> &count, int start, int end) {
        if (end <= start) {
            return;
        }

        swap(count[start], count[(rand() % (end - start + 1)) + start]);
        int l = start, r = end;
        pair<char, int> key = count[l];

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
        quickSort(count, start, r - 1);
        quickSort(count, r + 1, end);
    }

    string frequencySort(string s) {
        unordered_map<char, int> countMap;
        for (auto &ch: s) {
            ++countMap[ch];
        }

        vector<pair<char, int>> count(countMap.size());
        int i = 0;
        for (auto &each: countMap) {
            count[i++] = each;
        }

        quickSort(count, 0, count.size() - 1);

        string ans = "";
        for (auto &each: count) {
            for (int j = 0; j < each.second; ++j) {
                ans += each.first;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0451_H
