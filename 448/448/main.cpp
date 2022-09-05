#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int index = 0;
        while (index < nums.size())
        {
            if (nums[index] < 0)
            {
                index += 1;
            }
            else if (nums[index] == index + 1)
            {
                index += 1;
            }
            else if(nums[nums[index] - 1] == nums[index])
            {
                nums[index] = -1;
                index += 1;
            }
            else
            {
                int t = nums[nums[index] - 1];
                nums[nums[index] - 1] = nums[index];
                nums[index] = t;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {
        4,3,2,7,8,2,3,1
    };
    s.findDisappearedNumbers(nums);
}