#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int left = 0;
        int right = 0;
        int result = 0;
        while (right < nums.size())
        {
            //窗口右端滑动
            while (right < nums.size())
            {
                product *= nums[right];
                if (product >= k)
                {
                    break;
                }
                else
                {
                    result += right - left + 1;
                    right += 1;
                }
            }
            //右端滑动后，若未到头
            if (right < nums.size())
            {
                //窗口左端滑动
                while (left < right && product >= k)
                {
                    product /= nums[left];
                    left += 1;
                }
                //窗口左端滑动到合适位置时，检测当前是否符合
                if (product >= k)
                {
                    //不符合,重置窗口
                    left += 1;
                    right += 1;
                    product = 1;
                }
                else
                {
                    //符合要求
                    result += right - left + 1;
                    right += 1;
                }

            }
        }
        return result;
    }
};


int main()
{
    vector<int> nums = { 10,5,2,6};
    Solution solution = Solution();
    int k = 0;
    cout << solution.numSubarrayProductLessThanK(nums, k) << endl;
}