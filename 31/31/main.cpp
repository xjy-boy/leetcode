#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return;
        }
        int index = nums.size() - 2;
        int swapIndex = nums.size() - 1;
        while (index >= 0 && nums[index + 1] <= nums[index])
        {
            index -= 1;
        }
        if (index >= 0)
        {
            while (swapIndex > index && nums[index] >= nums[swapIndex])
            {
                swapIndex -= 1;
            }
            int t = nums[index];
            nums[index] = nums[swapIndex];
            nums[swapIndex] = t;
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,5,1 };
    s.nextPermutation(nums);
}
