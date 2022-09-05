#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int presum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            sum -= nums[i];
            if (presum == sum)
            {
                return i;
            }
            else
            {
                presum += nums[i];
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = { 1,2,3 };
    Solution solution = Solution();
    cout << solution.pivotIndex(nums) << endl;
}