#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            int dif = nums[i] - nums[i - 1];
            if (dif > ans)
            {
                ans = dif;
            }
        }
        return ans;
    }
};