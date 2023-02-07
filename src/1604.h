#ifndef LEETCODE_1604_H
#define LEETCODE_1604_H

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int n = keyName.size();
        unordered_map<string, vector<int>> record;
        vector<string> ans;

        for (int i = 0; i < n; ++i) {
            int min = stoi(keyTime[i]) * 60 + stoi(keyTime[i].substr(3));
            record[keyName[i]].push_back(min);
        }

        for (auto &each: record) {
            const string &name = each.first;
            std::sort(record[name].begin(), record[name].end());
            int left = 0, right = 0;
            while (right < record[name].size()) {
                while (left < right and record[name][right] - record[name][left] > 60) {
                    ++left;
                }

                if (right - left + 1 >= 3) {
                    ans.push_back(name);
                    break;
                }

                ++right;
            }
        }

        std::sort(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODE_1604_H
