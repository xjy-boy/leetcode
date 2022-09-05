#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int pre = INT_MAX;
        int minNum = INT_MAX;
        int index = 0;
        while (index < nums.size())
        {
            if (nums[index] > pre)
            {
                return true;
            }

            if (nums[index] < minNum)
            {
                minNum = nums[index];
            }
            else if (nums[index] > minNum)
            {
                pre = min(pre, nums[index]);
            }
            index += 1;
        }
        return false;
    }
};