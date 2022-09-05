#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left = 0;
        int index = 0;
        while (left < nums.size() - 1&& index < nums.size() && index <= left)
        {
            left = max(nums[index] + index, left);
            index += 1;
        }
        return left >= nums.size() - 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,0,4 };
    cout << s.canJump(nums) << endl;
}