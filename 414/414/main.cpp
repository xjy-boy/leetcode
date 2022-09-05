#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;

        if (nums.size() >= 3)
        {
            max1 = max(nums[0], max(nums[1], nums[2]));
        }     
        for (int num : nums)
        {
            if (num == max1 || num == max2 || num == max3)
            {
                continue;
            }
            if (num > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
            {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3)
            {
                max3 = num;
            }
        }

        if (max3 == LONG_MIN)
        {
            return max1;
        }
        else
        {
            return max3;
        }
    }
};

