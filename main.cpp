#include <iostream>
#include <utility>
#include "0048.h"

using namespace std;


int main() {
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    solution.rotate(matrix);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
