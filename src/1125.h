#ifndef LEETCODE_1125_H
#define LEETCODE_1125_H

/**
 * 首先进行状态压缩，将所需技能和每个人的技能都转为一个二进制数字
 *
 * dp[j]: 只考虑前 i 个人，所需技能为 j 时，选出的最小人员名单
 *
 * dp[j] = min( dp[i-1][j], dp[i-1][j-skill[i-1]] + (i-1) )  , dp[i-1][j] != null and dp[i-1][j-skill[i-1]] != null
 *          = dp[i-1][j]                                        , else and dp[i-1][j] != null
 *
 * dp[0][j] = 0     , j = 0
 *          = null  , j > 0
 */

#include <vector>
#include <unordered_map>

using std::vector, std::string;

class Solution {
public:
    using people_list = vector<int>;

    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
        auto skill_n = req_skills.size();
        auto people_n = people.size();
        int req = (1 << skill_n) - 1;

        int pos = 0;
        std::unordered_map<string, int> map;
        for (const auto &each: req_skills) {
            map[each] = pos;
            ++pos;
        }

        vector<int> skills;
        skills.reserve(people_n);
        for (const auto &each: people) {
            int s = 0;
            for (const auto &skill: each) {
                s |= (1 << map[skill]);
            }
            skills.push_back(s);
        }

        vector<people_list *> dp_pre = vector(req + 1, static_cast<people_list *>(nullptr));
        vector<people_list *> dp = vector(req + 1, static_cast<people_list *>(nullptr));
        dp_pre[0] = new vector<int>;

        for (int i = 1; i < people_n + 1; ++i) {
            for (int j = 0; j <= req; ++j) {
                int remain_skill = j & (~skills[i - 1]);
                if (dp_pre[j] != nullptr and dp_pre[remain_skill] != nullptr) {
                    if (dp_pre[j]->size() < dp_pre[remain_skill]->size() + 1) {
                        dp[j] = new vector(dp_pre[j]->begin(), dp_pre[j]->end());
                    } else {
                        dp[j] = new vector(dp_pre[remain_skill]->begin(), dp_pre[remain_skill]->end());
                        dp[j]->push_back(i - 1);
                    }
                } else if (dp_pre[j] != nullptr) {
                    dp[j] = new vector(dp_pre[j]->begin(), dp_pre[j]->end());
                } else if (dp_pre[remain_skill] != nullptr) {
                    dp[j] = new vector(dp_pre[remain_skill]->begin(), dp_pre[remain_skill]->end());
                    dp[j]->push_back(i - 1);
                }
            }
            std::swap(dp_pre, dp);
        }

        return *dp_pre[req];
    }
};

#endif //LEETCODE_1125_H
