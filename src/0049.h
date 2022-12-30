#ifndef LEETCODE_0049_H
#define LEETCODE_0049_H

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (auto &str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto &each: map) {
            ans.push_back(each.second);
        }

        return ans;
    }
};

#endif //LEETCODE_0049_H
