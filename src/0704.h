#include <vector>

using namespace std;

class Solution {
public:
    int target;
    vector<int> nums;

    int search(vector<int> &n, int t) {
        this->target = t;
        this->nums = n;

        return this->search_in(0, n.size() - 1);
    }

    int search_in(int start, int end) {
        if (start > end) {
            return -1;
        }

        int mid = (start + end) / 2;
        if (this->nums[mid] == target) {
            return mid;
        } else if (this->nums[mid] > target) {
            return search_in(start, mid - 1);
        } else {
            return search_in(mid + 1, end);
        }
    }
};
