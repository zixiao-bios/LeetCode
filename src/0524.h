#ifndef LEETCODE_0524_H
#define LEETCODE_0524_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(const string &target, const string &source) {
        int pt = 0, ps = 0;

        while (ps < source.size()) {
            while (source[ps] != target[pt]) {
                ++ps;
                if (ps == source.size()) {
                    return false;
                }
            }

            ++ps, ++pt;
            if (pt == target.size()) {
                return true;
            }
        }

        return false;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),  dictionary.end(), [](const string &a, const string &b) {
            if (a.size() != b.size()) {
                return a.size() > b.size();
            } else {
                return a <= b;
            }
        });

        for (auto & i : dictionary) {
            if (check(i, s)) {
                return i;
            }
        }

        return "";
    }
};

#endif //LEETCODE_0524_H
