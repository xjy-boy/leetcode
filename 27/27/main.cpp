#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (val > 50 || nums.empty())
        {
            return nums.size();
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            while (left<right && nums[left] != val)
            {
                left += 1;
            }
            while (left < right && nums[right] == val)
            {
                right -= 1;
            }
            nums[left] = nums[right];
            right -= 1;
        }
        if (nums[left] == val)
        {
            return left;
        }
        else
        {
            return left + 1;
        }
    }
};

int main()
{
    vector<int> nums = {3,2,2,3};
    Solution s;
    cout << s.removeElement(nums, 3) << endl;
}