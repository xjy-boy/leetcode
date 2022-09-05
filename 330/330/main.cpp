#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        //µ±Ç°¸²¸ÇÇøÓò
        long now = 1;
        int index = 0;
        while (now <= n)
        {
            if (index < nums.size() && nums[index] <= now)
            {
                now += nums[index];
                index += 1;
            }
            else
            {
                now = now << 1;
                ans += 1;
            }
        }
        return ans;
    }
};