#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for (int i = 0; i < machines.size(); i++)
        {
            sum += machines[i];
        }
        if (sum % machines.size() != 0)
        {
            return -1;
        }
        sum = sum / machines.size();
        int ans = 0;
        int pre = 0;
        for (int i = 0; i < machines.size(); i++)
        {
            pre += machines[i] - sum;
            if (abs(pre) > ans)
            {
                ans = abs(pre);
            }
            if (machines[i] - sum > ans)
            {
                ans = machines[i] - sum;
            }
        }
        return ans;
    }
};