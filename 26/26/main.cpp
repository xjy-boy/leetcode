#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int index = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[index] = nums[i];
                index += 1;
            }
        }
        nums.erase(nums.begin() + index,nums.end());
        return nums.size();
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
    s.removeDuplicates(nums);
}