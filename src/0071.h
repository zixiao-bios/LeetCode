#ifndef LEETCODE_0071_H
#define LEETCODE_0071_H

#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<string> get_name_list(const string &path) {
        vector<string> name_list;

        int i = 0;
        while (true) {
            while (i < path.size() and path[i] == '/') {
                ++i;
            }

            if (i == path.size()) {
                return name_list;
            } else {
                int left = i;
                i = path.find('/', i);
                if (i == string::npos) {
                    i = path.size();
                    name_list.push_back(path.substr(left, path.size() - left));
                } else {
                    name_list.push_back(path.substr(left, i - left));
                }
            }
        }
    }

    string simplifyPath(string path) {
        auto name_list = get_name_list(path);
        deque<string> deque;

        for (auto &name: name_list) {
            if (name == "..") {
                if (!deque.empty()) {
                    deque.pop_back();
                }
            } else if (name != ".") {
                deque.push_back(name);
            }
        }

        string ans;
        for (auto &each: deque) {
            ans += "/" + each;
        }

        return ans.empty() ? "/" : ans;
    }
};

#endif //LEETCODE_0071_H
