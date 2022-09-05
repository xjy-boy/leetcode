#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        int t = 1;
        int numMax = INT_MIN;
        for (int num : nums)
        {
            if (num & t)
            {
                count += 1;
            }
            if (num > numMax)
            {
                numMax = num;
            }
        }
        ans += (nums.size() - count) * count;
        while (true)
        {
            t = t << 1;
            count = 0;
            for (int num : nums)
            {
                if (num & t)
                {
                    count += 1;
                }
            }
            ans += (nums.size() - count) * count;
            if (t == (1 << 31) || t > numMax)
            {
                break;
            }
        }
        return ans;
    }
};