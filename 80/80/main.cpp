#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        bool flag = true;
        for (int i = 1; i < nums.size(); i++)
        {

            if (nums[i] != nums[i - 1])
            {
                nums[index] = nums[i];
                index += 1;
                flag = true;
            }
            else
            {
                if (flag)
                {
                    nums[index] = nums[i];
                    index += 1;
                    flag = false;
                }
            }
        }
        nums.erase(nums.begin() + index, nums.end());
        return nums.size();
    }
};