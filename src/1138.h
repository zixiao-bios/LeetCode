#ifndef LEETCODE_1138_H
#define LEETCODE_1138_H

using namespace std;

class Solution {
public:
    static const pair<int, int> &get_position(const char &ch) {
        int n = ch - 'a';
        static pair<int, int> position;
        position.first = n / 5;
        position.second = n - 5 * position.first;
        return position;
    }

    string alphabetBoardPath(string target) {
        string ans;
        pair<int, int> pos = {0, 0}, new_pos;
        for (auto &ch: target) {
            new_pos = get_position(ch);

            int row = new_pos.first - pos.first;
            int col = new_pos.second - pos.second;

            if (col < 0) {
                // move left
                ans += string(-col, 'L');
            }

            if (row > 0) {
                // move down
                ans += string(row, 'D');
            }

            if (row < 0) {
                // move up
                ans += string(-row, 'U');
            }

            if (col > 0) {
                // move right
                ans += string(col, 'R');
            }

            ans += '!';
            pos.swap(new_pos);
        }

        return ans;
    }
};

#endif //LEETCODE_1138_H
