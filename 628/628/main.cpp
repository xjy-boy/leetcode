#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //1.三个最大的
        //2.两个最小的，一个最大的
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int& num : nums)
        {
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

            if (num < min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2)
            {
                min2 = num;
            }
        }
        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};