#ifndef LEETCODE_2559_H
#define LEETCODE_2559_H

#include <vector>
#include <unordered_set>

using std::vector;

class Solution {
public:
    std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

    vector<int> vowelStrings(vector<std::string> &words, vector<vector<int>> &queries) {
        auto n = words.size();

        std::vector<int> val;
        val.reserve(n);
        for (const auto &word: words) {
            val.push_back(is_vowel_word(word));
        }

        std::vector<int> prefix_sum(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + val[i - 1];
        }

        std::vector<int> ans;
        ans.reserve(queries.size());
        for (const auto &query: queries) {
            ans.push_back(prefix_sum[query[1] + 1] - prefix_sum[query[0]]);
        }
        return ans;
    }

    bool is_vowel_word(const std::string &s) {
        return vowels.find(*s.begin()) != vowels.end() and vowels.find(*(s.end() - 1)) != vowels.end();
    }
};

#endif //LEETCODE_2559_H
