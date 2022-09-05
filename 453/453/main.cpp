#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int now = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < now)
            {
                ans += (now - nums[i]) * i;
                now = nums[i];
            }
            else
            {
                ans += nums[i] - now;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3,2,1 };
    cout << s.minMoves(nums) << endl;
}