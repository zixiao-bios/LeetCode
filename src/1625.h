#ifndef LEETCODE_1625_H
#define LEETCODE_1625_H

#include <unordered_set>
#include <queue>

using std::string;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        std::queue<string> queue;
        std::unordered_set<string> visit;
        string ans = s;

        queue.push(s);
        while (!queue.empty()) {
            string t = queue.front();
            queue.pop();
            ans = std::min(ans, t);

            string s1 = t;
            for (int i = 1; i < s1.size(); i += 2) {
                s1[i] = static_cast<char>((s1[i] - '0' + a) % 10 + '0');
            }
            string s2 = t.substr(s.size() - b, b) + t.substr(0, s.size() - b);

            for (const auto &each: {s1, s2}) {
                if (visit.find(each) == visit.end()) {
                    visit.insert(each);
                    queue.push(each);
                }
            }
        }

        return ans;
    }
};

#endif //LEETCODE_1625_H
