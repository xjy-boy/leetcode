#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = 0;
        int i = 0;
        int sum = 0;
        while (length < nums.size() && sum < target)
        {
            sum += nums[length];
            length++;
        }
        if (sum < target)
        {
            return 0;
        }
        while (true)
        {
            //Ëõ¶Ì×ó¶Ë
            while (sum - nums[i] >= target)
            {
                sum -= nums[i];
                i++;
                length -= 1;
            }
            if (i + length >= nums.size())
            {
                break;
            }
            i += 1;
            sum = sum + nums[i + length - 1] - nums[i - 1];
        }

        return length;
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> nums = {5,1,3,5,10,7,4,9,2,8 };
    int target = 15;
    cout << solution.minSubArrayLen(target, nums) << endl;
}