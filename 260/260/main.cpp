#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
        {
            sum = sum ^ num;
        }
        int temple = 1;
        while (!(sum & temple))
        {
            temple = temple << 1;
        }
        int ans1 = 0;
        int ans2 = 0;
        for (int num : nums)
        {
            if (num & temple)
            {
                ans1 = ans1 ^ num;
            }
            else
            {
                ans2 = ans2 ^ num;
            }
        }
        return { ans1,ans2 };
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,2,2,3,5 };
    s.singleNumber(nums);
}