#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int now1 = 1;
        int now2 = 1;
        int ans = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                now1 = 1;
                now2 = 1;
                ans = max(ans, 0);
            }

            int next1 = now1 * nums[i];
            int next2 = now2 * nums[i];
            now1 = max(next1, next2);
            now2 = min(next1, next2);
            ans = max(ans, now1);
            now1 = max(now1, 1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-2,1,-1};
    cout << s.maxProduct(nums) << endl;
}