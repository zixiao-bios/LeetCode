#ifndef LEETCODE_0068_H
#define LEETCODE_0068_H

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<string> ans;

    void generate_line(const vector<string> &words, int start, int end, int max_width) {
        int ch_num = 0;
        for (int i = start; i <= end; ++i) {
            ch_num += words[i].size();
        }

        int space_num = max_width - ch_num;
        int word_num = end - start + 1;
        int blank_num = word_num - 1;
        string line;

        if (word_num == 1) {
            line = words[start];
            line += string(space_num, ' ');
        } else {
            int blank_space_num = space_num / blank_num;
            int big_blank_num = space_num % blank_num;

            for (int i = 0; i < blank_num; ++i) {
                line += words[start];
                ++start;
                if (i < big_blank_num) {
                    line += string(blank_space_num + 1, ' ');
                } else {
                    line += string(blank_space_num, ' ');
                }
            }
            line += words[end];
        }

        ans.push_back(line);
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        int line_width = 0;
        int start = 0;

        for (int i = 0; i < words.size(); ++i) {
            if (line_width + words[i].size() > maxWidth) {
                // fill this line
                generate_line(words, start, i - 1, maxWidth);
                start = i;
                line_width = words[i].size() + 1;
            } else {
                // add word to this line
                line_width += words[i].size() + 1;
            }
        }

        string line;
        for (int i = start; i < words.size(); ++i) {
            line += words[i];
            if (i != words.size() - 1) {
                line += " ";
            }
        }
        line += string(maxWidth - line.size(), ' ');
        ans.push_back(line);

        return ans;
    }
};

#endif //LEETCODE_0068_H
