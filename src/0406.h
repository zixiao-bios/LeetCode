#ifndef LEETCODE_0406_H
#define LEETCODE_0406_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0]) {
                return a[0] > b[0];
            } else {
                return a[1] < b[1];
            }
        });

        vector<vector<int>> ans;
        for (int i = 0; i < people.size(); ++i) {
            ans.insert(ans.begin() + people[i][1], people[i]);
        }

        return ans;
    }
};

#endif //LEETCODE_0406_H
