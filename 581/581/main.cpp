#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // biggest[i] 为i左侧(包括i)最大的数
        // smallest[i] 为i右侧(包括i)最小的数
        vector<int> biggest = vector<int>(nums.size(), 0);
        vector<int> smallest = vector<int>(nums.size(), 0);
        
        int bigNum = INT_MIN;
        int smallNum = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            bigNum = max(bigNum, nums[i]);
            smallNum = min(smallNum, nums[nums.size() - i - 1]);
            biggest[i] = bigNum;
            smallest[nums.size() - i - 1] = smallNum;
        }
        int left = 0;
        int right = nums.size() - 1;
        int t = INT_MIN;
        while (left < nums.size() && nums[left] >= t && nums[left] <= smallest[left])
        {
            t = nums[left];
            left += 1;
        }

        t = INT_MAX;
        while (right > left && nums[right] <= t && nums[right] >= biggest[right])
        {
            t = nums[right];
            right -= 1;
        }

        if (right == left)
        {
            return 0;
        }
        else
        {
            return right - left + 1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,6,4,8,10,9,15 };
    cout << s.findUnsortedSubarray(nums) << endl;
}