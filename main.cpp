#include <iostream>

#include "0542.h"

using namespace std;

int main() {
    Solution s = Solution();
    vector<vector<int>> matrix = {{0, 0, 0},
                                  {0, 1, 0},
                                  {1, 1, 1}};
    s.updateMatrix(matrix);
    return 0;
}
