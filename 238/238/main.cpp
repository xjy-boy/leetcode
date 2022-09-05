#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        ans[0] = nums[0];
        for (int i = 1; i < nums.size() - 1; i++)
        {
            ans[i] = ans[i - 1] * nums[i];
        }
        int last = 1;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            ans[i] = last * ans[i - 1];
            last *= nums[i];
        }
        ans[0] = last;
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,4 };
    s.productExceptSelf(nums);
}