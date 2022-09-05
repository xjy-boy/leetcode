#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n = 0;
        int ans1 = 0;
        int ans2 = 0;
        for (int num : nums)
        {
            n ^= num;
        }
        int div = 1;
        while ((div & n) == 0)
        {
            div = div << 1;
        }

        for (int num : nums)
        {
            if (num & div)
            {
                ans1 ^= num;
            }
            else
            {
                ans2 ^= num;
            }
        }
        return { ans1,ans2 };
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,5,2 };
    s.singleNumbers(nums);
}