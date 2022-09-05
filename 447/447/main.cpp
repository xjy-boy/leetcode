#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        unordered_map<int, int> disNum;
        for (int i = 0; i < points.size(); i++)
        {
            disNum.clear
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int dis = x * x + y * y;
                if (disNum.count(dis))
                {
                    int num = disNum[dis];
                    ans += num;
                    disNum[dis] = num + 1;
                }
                else
                {
                    disNum[dis] = 1;
                }
            }
        }
        return ans * 2;
    }
};