#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans = vector<int>(nums.size(), -1);

        vector<int> littleStack;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!littleStack.empty() && nums[littleStack.back()] < nums[i])
            {
                ans[littleStack.back()] = nums[i];
                littleStack.pop_back();
            }
            littleStack.emplace_back(i);
        }

        int index = 0;
        while (nums[littleStack.back()] < nums[littleStack[0]])
        {
            while (!littleStack.empty() && nums[littleStack.back()] < nums[index])
            {
                ans[littleStack.back()] = nums[index];
                littleStack.pop_back();
            }
            index += 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,4,3 };
    s.nextGreaterElements(nums);
}