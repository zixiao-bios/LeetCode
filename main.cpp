#include <iostream>
#include "0524.h"
//
//using namespace std;
//
//int main() {
//    Solution s = Solution();
//    vector<vector<int>> matrix = {{0, 0, 0},
//                                  {0, 1, 0},
//                                  {1, 1, 1}};
//    s.updateMatrix(matrix);
//    return 0;
//}

#include <iostream>
#include <iomanip>

using namespace std;

void show_byte(char *p, size_t n) {
    for (int i = 0; i < n; ++i) {
        printf("%.2hhx ", p[i]);
    }
    printf("\n");
}

template<typename T>
void swap_inplace(T &a, T &b) {
    a = a ^ b;
    b = b ^ a;
    a = b ^ a;
}

int main() {
//    int a = 0xd2ff;
//    int *p = &a;
//    show_byte((char *) &a, sizeof a);
//    show_byte((char *) &p, sizeof p);

//    unsigned char ch = 0;
//    for (ch = 0; ch < 0xff; ++ch) {
//        printf("%c\t%.2hhx\n", ch, ch);
//    }

    int n = 4;
    int a[] = {1, 2, 3, 4};
    int first = 0, last = n - 1;
    for (; first < last; ++first, --last) {
        swap_inplace(a[first], a[last]);
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\t", a[i]);
    }
}
