#ifndef LEETCODE_1233_H
#define LEETCODE_1233_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool is_sub_dir(const string &par, const string &sub) {
        return sub.find(par + '/') == 0;
    }

    vector<string> removeSubfolders(vector<string> &folder) {
        sort(folder.begin(), folder.end());

        auto par = folder.begin();
        for (auto it = folder.begin() + 1; it != folder.end(); ++it) {
            if (is_sub_dir(*par, *it)) {
                *it = "";
            } else {
                par = it;
            }
        }
        folder.erase(
                remove_if(folder.begin(), folder.end(), [](const string &s) { return s == ""; }),
                folder.end()
        );

        return folder;
    }
};

#endif //LEETCODE_1233_H
