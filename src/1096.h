#ifndef LEETCODE_1096_H
#define LEETCODE_1096_H

#include <utility>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

class Solution {
public:
    set<string> res;

    vector<string> braceExpansionII(string expression) {
        process(expression);
        return {res.begin(), res.end()};
    }

    void process(const string &exp) {
        int end = exp.find_first_of('}');

        if (end == string::npos) {
            res.insert(exp);
            return;
        }

        int start = exp.find_last_of('{', end);

        string prefix = exp.substr(0, start);
        string suffix = exp.substr(end + 1);

        string x;
        stringstream ss(exp.substr(start + 1, end - start - 1));
        while (getline(ss, x, ',')) {
            process(prefix + x + suffix);
        }
    }
};

#endif //LEETCODE_1096_H
