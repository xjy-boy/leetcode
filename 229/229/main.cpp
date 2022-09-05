#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ans1 = 0;
        int ans2 = 0;

        int count1 = 0;
        int count2 = 0;
        for (int num : nums)
        {
            if (count1 != 0 && num == ans1)
            {
                count1 += 1;
            }
            else if (count2 != 0 && num == ans2)
            {
                count2 += 1;
            }
            else if (count1 == 0)
            {
                ans1 = num;
                count1 += 1;
            }
            else if (count2 == 0)
            {
                ans2 = num;
                count2 += 1;
            }
            else
            {
                count1 -= 1;
                count2 -= 1;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int num : nums)
        {
            if (num == ans1)
            {
                count1 += 1;
            }
            else if (num == ans2)
            {
                count2 += 1;
            }
        }
        vector<int> ans;
        if (count1 > nums.size() / 3)
        {
            ans.emplace_back(ans1);
        }
        if(count2 > nums.size()/3)
        {
            ans.emplace_back(ans2);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,1,1,3,1,4,5,6 };
    s.majorityElement(nums);
}