#ifndef LEETCODE_0524_H
#define LEETCODE_0524_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string &a, string &b) {
            if (a.size() != b.size()) {
                return a.size() > b.size();
            } else {
                return a < b;
            }
        });


        for (const auto &word: dictionary) {
            int pw = 0, ps = 0;
            while (pw < word.size() and ps < s.size()) {
                if (word[pw] == s[ps]) {
                    ++pw;
                }
                ++ps;
            }
            if (pw == word.size()) {
                return word;
            }
        }

        return "";
    }
};

#endif //LEETCODE_0524_H
