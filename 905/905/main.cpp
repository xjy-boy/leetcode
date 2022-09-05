#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            while (left < right && nums[left] % 2 == 0)
            {
                left += 1;
            }

            while (left < right && nums[right] % 2 != 0)
            {
                right -= 1;
            }
            int t = nums[left];
            nums[left] = nums[right];
            nums[right] = t;
        }
        return nums;
    }
};