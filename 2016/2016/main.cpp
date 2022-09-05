#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max = 0;
        int result = -1;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (i != 0 && nums[i] > nums[i - 1])
            {
                continue;
            }
            for (int j = i+1; j < nums.size(); j++)
            {
                //更新最大值
                if (max <= i || nums[j] > nums[max])
                {
                    max = j;
                }
            }
            if (nums[max] != nums[i] && result < nums[max] - nums[i])
            {
                result = nums[max] - nums[i];
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = { 1,5,2,10 };
    Solution s;
    cout << s.maximumDifference(nums) << endl;
}