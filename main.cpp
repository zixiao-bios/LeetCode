#include <iostream>
#include "0695_2.h"
#include <map>
#include <unordered_map>

using namespace std;

int main() {
//    Solution s = Solution();
//    vector<vector<int>> matrix = {{0, 0, 0},
//                                  {0, 1, 0},
//                                  {1, 1, 1}};
//    s.updateMatrix(matrix);
//    return 0;

    unordered_map<int, int> map1;
    map1[4] = 104;
    map1[2] = 102;
    map1[9] = 109;
    map1[5] = 105;
    map1[3] = 103;
    for (auto &each: map1) {
        cout << each.first << " " << each.second << endl;
    }
}
