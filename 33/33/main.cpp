#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }

    int search(vector<int>& nums, int target,int left, int right) {
        if (left == right)
        {
            if (nums[left] == target)
            {
                return left;
            }
            else
            {
                return -1;
            }
        }
        else if(nums[left] < nums[right])
        {
            auto it = lower_bound(nums.begin() + left, nums.begin() + right + 1, target);
            if (it != nums.begin() + right + 1 && *it == target)
            {
                return it - nums.begin();
            }
            else
            {
                return -1;
            }
        }
        int mid = (left + right) / 2;
        if (nums[mid] >= nums[left])
        {
            if (target >= nums[left] && target <= nums[mid])
            {
                return search(nums, target, left, mid);
            }
            else
            {
                return search(nums, target, mid + 1, right);
            }
        }
        else
        {
            if (target <= nums[right] && target >= nums[mid])
            {
                return search(nums, target, mid, right);
            }
            else
            {
                return search(nums, target, left, mid);
            }
        }
    }
};

int main()
{
    vector<int> nums = { 3,1 };
    Solution s;
    cout << s.search(nums,1);
}