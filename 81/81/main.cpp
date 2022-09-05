#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[left] == nums[mid] && nums[mid] == nums[right] )
            {
                left += 1;
                right -= 1;
            }
            //left Óëmid¼äÓÐÐò
            else if (nums[left] <= nums[mid])
            {
                if (target < nums[mid] && target >= nums[left])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {};
    cout << s.search(nums, 1) << endl;
}