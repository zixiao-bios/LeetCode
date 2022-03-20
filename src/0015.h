#ifndef LEETCODE_0015_H
#define LEETCODE_0015_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2;) {
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    do {
                        ++left;
                    } while (left < right and nums[left] == nums[left - 1]);

                    do {
                        --right;
                    } while (left < right and nums[right] == nums[right + 1]);

                } else if(nums[i] + nums[left] + nums[right] < 0){
                    do {
                        ++left;
                    } while (left < right and nums[left] == nums[left - 1]);

                } else {
                    do {
                        --right;
                    } while (left < right and nums[right] == nums[right + 1]);
                }
            }

            do {
                ++i;
            } while (i < nums.size() - 2 and nums[i] == nums[i - 1]);
        }

        return ans;
    }
};

#endif //LEETCODE_0015_H
