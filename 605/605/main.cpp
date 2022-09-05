#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0)
        {
            return true;
        }
        vector<int> dp = { 0,0 };
        int index = 0;
        int i = 0;
        while (i < flowerbed.size())
        {
            index = i % 2;
            if (flowerbed[i] == 1)
            {
                dp[index] = dp[1 - index];
            }
            else if (i + 1 < flowerbed.size() 
                && flowerbed[i+1] == 1)
            {
                dp[index] = dp[1 - index];
            }
            else if(i > 0 && flowerbed[i - 1] == 1)
            {
                dp[index] = dp[1 - index];
            }
            else
            {
                dp[index] = dp[index] + 1;
                if (dp[index] >= n)
                {
                    return true;
                }
            }
            i += 1;
        }
        return false;
    }
};