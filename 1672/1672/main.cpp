#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (vector<int> account : accounts)
        {
            int sum = 0;
            for (int num : account)
            {
                sum += num;
            }
            if (sum > ans)
            {
                ans = sum;
            }
        }
        return ans;
    }
};