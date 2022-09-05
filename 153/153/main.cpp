#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right && nums[left] > nums[right])
        {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right] && nums[mid] < nums[left])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution s;
    cout << s.findMin(nums) << endl;
}