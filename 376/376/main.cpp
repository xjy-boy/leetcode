#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 摆动序列分两种情况        
        int up = 1;
        int down = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                up = max(up, down + 1);
            }
            else if (nums[i] < nums[i - 1])
            {
                down = max(down, up + 1);
            }
        }

        return max(up, down);
    }
};

int main()
{
    vector<int> nums = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    Solution s;
    cout << s.wiggleMaxLength(nums) << endl;
}