#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int loop_x = 0; //一次循环的横坐标长度
        int loop_y = 0; //一次循环的纵坐标长度
        int sum = 0;

        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'U') {
                loop_y += 1;
            }
            else{
                loop_x += 1;
            }
        }
        sum = loop_x * loop_y;
        vector<vector<bool>> is_reach; // 是否会经过
        for (int i = 0; i < loop_x + 1; i++) {
            is_reach.push_back(vector<bool>(loop_y + 1,false));
        }

        

        //记录一次循环中的坐标
        int location_x = 0;
        int location_y = 0;
        is_reach[0][0] = true;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'U') {
                location_y += 1;
            }
            else {
                location_x += 1;
            }
            is_reach[location_x][location_y] = true;
        }

        int temp_x = x / loop_x;
        int temp_y = y / loop_y;
        int end_x = x;
        int end_y = y;
        if (temp_x < temp_y) {
            end_x = x % loop_x;
            end_y = y - temp_x * loop_y;
        }
        else {
            end_y = y % loop_y;
            end_x = x - temp_y * loop_x;
        }
        if (end_x > loop_x || end_y > loop_y) {
            return false;
        }
        // 检查终点是否能到达
        if (!is_reach[end_x][end_y]) {
            return false;
        }
        else {
            for (int i = 0; i < obstacles.size(); i++) {
                int obstacle_x = obstacles[i][0];
                int obstacle_y = obstacles[i][1];
                if (obstacle_x > x || obstacle_y > y) {
                    continue;
                }
                temp_x = obstacle_x / loop_x;
                temp_y = obstacle_y / loop_y;

                if (temp_x < temp_y) {
                    obstacle_x = obstacle_x % loop_x;
                    obstacle_y = obstacle_y - temp_x * loop_y;
                }
                else {
                    obstacle_y = obstacle_y % loop_y;
                    obstacle_x = obstacle_x - temp_y * loop_x;
                }
                if (obstacle_x > loop_x || obstacle_y > loop_y) {
                    continue;
                }

                // 检查障碍物是否能到达
                if (is_reach[obstacle_x][obstacle_y]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution solution = Solution();
    string command = "URRURRR";
    vector<vector<int>> obstacles = { {7, 7 }, { 0, 5 }, { 2, 7 }, { 8, 6 }, { 8, 7 }, { 6, 5 }, { 4, 4 }, { 0, 3 }, { 3, 6 }
};
    int x = 4915, y = 1966;
    cout << solution.robot(command, obstacles, x, y) << endl;
}