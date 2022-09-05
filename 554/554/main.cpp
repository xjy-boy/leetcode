#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> pre;
        int sum = 0;
        int ans = 0;
        int next = 0;
        for (vector<int>& row : wall)
        {
            sum = 0;
            for (int i = 0; i < row.size() - 1; i++)
            {
                sum += row[i];
                if (pre.count(sum))
                {
                    next = pre[sum] + 1;
                    pre[sum] = next;
                }
                else
                {
                    next = 1;
                    pre[sum] = next;
                }
                if (next > ans)
                {
                    ans = next;
                }
            }
        }
        return wall.size() - ans;
    }
};