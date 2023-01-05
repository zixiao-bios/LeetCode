#ifndef LEETCODE_0067_H
#define LEETCODE_0067_H

#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0, n = max(a.size(), b.size());
        string ans;
        for (int i = 0; i < n; ++i) {
            int sum = i >= a.size() ? 0 : a[i] - '0';
            sum += i >= b.size() ? 0 : b[i] - '0';
            sum += carry;
            carry = sum > 1 ? 1 : 0;
            ans += to_string(sum - 2 * carry);
        }

        if (carry) {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODE_0067_H
