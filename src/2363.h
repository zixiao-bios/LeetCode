#ifndef LEETCODE_2363_H
#define LEETCODE_2363_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        };

        sort(items1.begin(), items1.end(), cmp);
        sort(items2.begin(), items2.end(), cmp);

        vector<vector<int>> ans;
        auto it1 = items1.begin(), it2 = items2.begin();
        while (true) {
            if (it1 == items1.end()) {
                for (; it2 != items2.end(); ++it2) {
                    ans.push_back(*it2);
                }
                break;
            } else if (it2 == items2.end()) {
                for (; it1 != items1.end(); ++it1) {
                    ans.push_back(*it1);
                }
                break;
            } else {
                if ((*it1)[0] < (*it2)[0]) {
                    ans.push_back(*it1);
                    ++it1;
                } else if ((*it1)[0] > (*it2)[0]) {
                    ans.push_back(*it2);
                    ++it2;
                } else {
                    ans.push_back({(*it1)[0], (*it1)[1] + (*it2)[1]});
                    ++it1, ++it2;
                }
            }
        }

        return ans;
    }
};

#endif //LEETCODE_2363_H
