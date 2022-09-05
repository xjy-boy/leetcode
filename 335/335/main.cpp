#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();

        // 处理第 1 种情况
        int i = 0;
        while (i < n && (i < 2 || distance[i] > distance[i - 2])) {
            ++i;
        }

        if (i == n) {
            return false;
        }

        // 处理第 j 次移动的情况
        if ((i == 3 && distance[i] == distance[i - 2])
            || (i >= 4 && distance[i] >= distance[i - 2] - distance[i - 4])) {
            //修改起点
            distance[i - 1] -= distance[i - 3];
        }
        ++i;

        // 处理第 2 种情况
        while (i < n && distance[i] < distance[i - 2]) {
            ++i;
        }

        return i != n;
    }
};

void main()
{
    Solution s;
    vector<int> dis = {
        1,2,2,3,2,2,
    };
    s.isSelfCrossing(dis);

};