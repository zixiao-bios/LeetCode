#ifndef LEETCODE_547_H
#define LEETCODE_547_H

#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ans;
                dfs(isConnected, visited, i);
            }
        }

        return ans;
    }

    void dfs(const vector<vector<int>>& map, vector<bool> &visited, int i) {
        if (visited[i]) {
            return;
        }

        visited[i] = true;
        for (int j = 0; j < visited.size(); ++j) {
            if (map[i][j]) {
                dfs(map, visited, j);
            }
        }
    }
};

#endif //LEETCODE_547_H
