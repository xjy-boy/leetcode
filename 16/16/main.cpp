#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 100000;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            int p = target - nums[i];
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (abs(sum - p) < abs(ans - target))
                {
                    ans = sum + nums[i];
                }
                if (sum < p)
                {
                    left += 1;
                }
                else
                {
                    right -= 1;
                }
            }
            if (ans == target)
            {
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,1,0 };
    cout << s.threeSumClosest(nums, 100) << endl;
}