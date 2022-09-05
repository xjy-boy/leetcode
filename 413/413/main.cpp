#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return 0;
        }
        int ans = 0;
        int index = 1;
        int pre = INT_MAX;
        int preLength = 0;
        while (index < nums.size())
        {
            int next = nums[index] - nums[index - 1];
            if (next == pre)
            {
                preLength += 1;
                ans += preLength - 2;
            }
            else
            {
                pre = next;
                preLength = 2;
            }
            index += 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,4,5 };
    cout << s.numberOfArithmeticSlices(nums) << endl;
}