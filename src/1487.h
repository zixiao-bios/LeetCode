#ifndef LEETCODE_1487_H
#define LEETCODE_1487_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string> &names) {
        unordered_map<string, int> map;
        vector<string> ans;

        for (auto &each: names) {
            if (map.find(each) != map.end()) {
                // map contains each
                int num = map.at(each);
                while (map.count(each + "(" + to_string(num) + ")")) {
                    ++num;
                }

                map.insert({each + "(" + to_string(num) + ")", 1});
                map.at(each) = num + 1;
                ans.push_back(each + "(" + to_string(num) + ")");
            } else {
                map.insert({each, 1});
                ans.push_back(each);
            }
        }

        return ans;
    }
};

#endif //LEETCODE_1487_H
