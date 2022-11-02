#ifndef LEETCODE_0547_2_H
#define LEETCODE_0547_2_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        stack<int> stack;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ans;
                int j = i;

                while (true) {
                    if (!visited[j]) {
                        visited[j] = true;
                        for (int k = 0; k < n; ++k) {
                            if (isConnected[j][k]) {
                                stack.push(k);
                            }
                        }
                    }

                    if (stack.empty()) {
                        break;
                    } else {
                        j = stack.top();
                        stack.pop();
                    }
                }
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0547_2_H
