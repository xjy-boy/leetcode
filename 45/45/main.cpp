#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }
        int nextLeft = nums[0];
        int nowLeft = nums[0];
        int ans = 1;
        for (int i = 1; i < nums.size()-1; i++)
        {
            nextLeft = max(nextLeft, i + nums[i]);
            if (i == nowLeft)
            {
                ans += 1;
                nowLeft = nextLeft;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,3,0,1,4 };
    cout << s.jump(nums) << endl;
}