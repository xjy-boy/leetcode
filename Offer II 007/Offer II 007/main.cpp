#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        while (false) 
        {
            cout << "test" << endl;
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int p = 0;
        int left = 0;
        int right = 0;
        int i = 0;
        while (i + 2 < nums.size())
        {
            p = nums[i];
            left = i + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] < -p) 
                {
                    left += 1;
                }
                else if (nums[left] + nums[right] > -p)
                {
                    right -= 1;
                }
                else
                {
                    result.push_back({ p,nums[left],nums[right] });
                    left += 1;
                    right -= 1;
                    //防止结果中有重复三元组
                    while (left < right && nums[left] == nums[left - 1]) 
                    {
                        left += 1;
                    }
                    while (right > left && nums[right] == nums[right + 1])
                    {
                        right -= 1;
                    }
                }
            }
            i += 1;
            //防止结果中有重复三元组
            while (i < (nums.size() - 2) && nums[i] == nums[i - 1])
            {
                i += 1;
            }
        }
        return result;
    }
};

int main() 
{
    //vector<int> nums = { -1,0,1,2,-1,-4 };
    vector<int> nums = { -1,0,1,2,-1,-4 ,-1,-1,-4};
    Solution solution = Solution();
    vector<vector<int>> result = solution.threeSum(nums);
    for (vector<int> list : result) 
    {
        cout << "{";
        for (int data : list)
        {
            cout << data << ",";
        }
        cout << "},";
    }
}