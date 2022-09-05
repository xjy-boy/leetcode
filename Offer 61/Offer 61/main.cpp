#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zeroNum = 0;
        while (zeroNum < nums.size() && nums[zeroNum] == 0)
        {
            zeroNum += 1;
        }
        for (int i = zeroNum; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] == nums[i])
            {
                return false;
            }
            zeroNum -= nums[i + 1] - nums[i] - 1;
        }
        return zeroNum >= 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,4,5 };
    s.isStraight(nums);
}