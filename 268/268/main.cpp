#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.emplace_back(-1);
       
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i && nums[i] != -1)
            {
                int num = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = num;
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -1)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};