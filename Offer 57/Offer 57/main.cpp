#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
            {
                left += 1;
            }
            else if (nums[left] + nums[right] == target)
            {
                break;
            }
            else
            {
                right -= 1;
            }
        }
        return { nums[left],nums[right] };
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,7,11,15 };
    int target = 9;
    s.twoSum(nums, target);
}