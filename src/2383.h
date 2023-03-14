#ifndef LEETCODE_2383_H
#define LEETCODE_2383_H

#include <vector>
#include <numeric>

using std::vector;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience) {
        int ans = 0;

        int total_energy = std::accumulate(energy.begin(), energy.end(), 0);
        if (initialEnergy <= total_energy) {
            ans += total_energy - initialEnergy + 1;
        }

        int exp = initialExperience;
        for (const auto &each: experience) {
            if (exp <= each) {
                ans += each - exp + 1;
                exp += each - exp + 1;
            }
            exp += each;
        }

        return ans;
    }
};

#endif //LEETCODE_2383_H
