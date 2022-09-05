#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }
        else
        {
            if (nums[0] > nums[1])
            {
                return 0;
            }
            
            if (nums.back() > nums[nums.size() - 2])
            {
                return nums.size() - 1;
            }
        }

        int left = 1;
        int right = nums.size() - 2;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1] && nums[mid] < nums[mid - 1])
            {
                return mid;
            }
            else if (nums[mid] > nums[mid + 1])
            {
                right = mid ;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};