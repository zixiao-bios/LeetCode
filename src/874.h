#ifndef LEETCODE_874_H
#define LEETCODE_874_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::vector;

class Robot {
public:
    explicit Robot(const vector<vector<int>> &obstacles) : pos_{0, 0}, face_(0) {
        for (const auto &each: obstacles) {
            obstacles_.insert(get_pos_idx({each[0], each[1]}));
        }
    };

    // 执行一次指令
    void action(int cmd) {
        if (cmd < 0) {
            face_ += (cmd * 2 + 3) * 90;
            face_ += 360;
            face_ %= 360;
        } else {
            for (int i = 0; i < cmd; ++i) {
                walk();
            }
        }
    }

    int get_dis_square() const {
        return pos_.first * pos_.first + pos_.second * pos_.second;
    }

private:
    // 向前走一步
    void walk() {
        std::pair<int, int> next_pos{pos_};
        next_pos.first += face_move_.at(face_).first;
        next_pos.second += face_move_.at(face_).second;

        if (obstacles_.find(get_pos_idx(next_pos)) == obstacles_.end()) {
            pos_ = next_pos;
        }
    }

    static int get_pos_idx(const std::pair<int, int> &pos) {
        return 60001 * pos.first + pos.second;
    }

    std::pair<int, int> pos_;
    int face_;
    const std::unordered_map<int, std::pair<int, int>> face_move_ = {{0,   {0,  1}},
                                                                     {90,  {1,  0}},
                                                                     {180, {0,  -1}},
                                                                     {270, {-1, 0}}};
    std::unordered_set<int> obstacles_{};
};

class Solution {
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        int ans = 0;
        Robot robot(obstacles);
        for (const auto &cmd: commands) {
            robot.action(cmd);
            ans = std::max(ans, robot.get_dis_square());
        }
        return ans;
    }
};

#endif //LEETCODE_874_H
