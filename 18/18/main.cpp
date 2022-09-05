#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
        {
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size() - 3)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                int left = j + 1;
                int right = nums.size() - 1;
                int p = target - nums[i] - nums[j];
                if (p < target / 2)
                {
                    break;
                }
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum < p)
                    {
                        left += 1;
                    }
                    else if(sum > p)
                    {
                        right -= 1;
                    }
                    else
                    {
                        ans.push_back({ nums[i],nums[j],nums[left],nums[right] });
                        left += 1;
                        right -= 1;
                        while (left < right && nums[left - 1] == nums[left])
                        {
                            left += 1;
                        }
                        while (left < right && nums[right + 1] == nums[right])
                        {
                            right -= 1;
                        }
                    }
                }
                while (j < nums.size() - 2 && nums[j + 1] == nums[j])
                {
                    j++;
                }
            }
            while (i < nums.size() - 3 && nums[i + 1] == nums[i])
            {
                i++;
            }
            i++;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {-1,-5,-5,-3,2,5,0,4};
    Solution s;
    s.fourSum(nums, -7);
}