#ifndef LEETCODE_547_H
#define LEETCODE_547_H

#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int ans = 0;

        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                ++ans;
                dfs(isConnected, visited, i);
            }
        }

        return ans;
    }
    
    void dfs(vector<vector<int>> &con, vector<bool> &visited, int n) {
        visited[n] = true;

        for (int i = 0; i < con.size(); ++i) {
            if (con[n][i] and !visited[i]) {
                dfs(con, visited, i);
            }
        }
    }
};

#endif //LEETCODE_547_H
