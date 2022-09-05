#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& u, const auto &v) {
            return u[1] < v[1];
        });

        int ans = 1;
        int pre = points[0][1];
        for (const vector<int>& balloon : points)
        {
            if (balloon[0] > pre) {
                pre = balloon[1];
                ans += 1;
            }
        }
        return ans;
    }
};