#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int right = nums.size() - 1;
        int left = 0;
        int t = 0;
        while (right > left)
        {
            while (right > left && nums[right] % 2 == 0)
            {
                right -= 1;
            }

            while (right > left && nums[left] % 2 == 1)
            {
                left += 1;
            }

            t = nums[right];
            nums[right] = nums[left];
            nums[left] = t;
        }
        return nums;
    }
};