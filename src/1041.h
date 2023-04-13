#ifndef LEETCODE_1041_H
#define LEETCODE_1041_H

#include <vector>

class Solution {
public:
    std::vector<std::pair<int, int>> directions = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
    };
    int direction = 0;

    std::pair<int, int> execute_command(const std::pair<int, int> &start, const std::string &command) {
        std::pair<int, int> pos(start);
        for (const auto &each: command) {
            switch (each) {
                case 'G':
                    pos.first += directions[direction].first;
                    pos.second += directions[direction].second;
                    break;
                case 'L':
                    direction = direction == 0 ? static_cast<int>(directions.size()) - 1 : direction - 1;
                    break;
                case 'R':
                    ++direction;
                    direction %= static_cast<int>(directions.size());
                    break;
                default:
                    ;
            }
        }
        return pos;
    }

    bool isRobotBounded(std::string instructions) {
        auto first_pos = execute_command({0, 0}, instructions);
        return (first_pos.first == 0 and first_pos.second == 0) or (direction != 0);
    }
};

#endif //LEETCODE_1041_H
