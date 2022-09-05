#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> preSum;
        int sum = 0;
        preSum[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = (sum + nums[i]) % k;
            if (preSum.count(sum))
            {
                if (i - preSum[sum] > 1)
                {
                    return true;
                }
            }
            else
            {
                preSum[sum] = i;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 23,2,6,4,7 };
    s.checkSubarraySum(nums, 13);
}