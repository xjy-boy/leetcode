#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(),
            [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });

        int n = intervals.size();
        int right = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] >= right)
            {
                ans += 1;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};