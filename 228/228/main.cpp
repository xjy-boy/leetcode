#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
        {
            return {};
        }
        vector<string> ans;
        int start = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                if (start == nums[i - 1])
                {
                    ans.emplace_back(to_string(start));
                }
                else
                {
                    ans.emplace_back(to_string(start) + "->" + to_string(nums[i-1]));
                }
                start = nums[i];
            }
        }
        if (nums.back() == start)
        {
            ans.emplace_back(to_string(start));
        }
        else
        {
            ans.emplace_back(to_string(start) + "->" + to_string(nums.back()));
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 0,2,3,4,6,8,9 };
    s.summaryRanges(nums);
}