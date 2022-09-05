#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int findKthLargest(vector<int>& nums, int left, int right,int k) {
        int midNum = nums[left];
        int l = left;
        int r = right;
        while (l < r)
        {
            while (r > l && nums[r] > midNum)
            {
                r -= 1;
            }
            if (r > l)
            {
                nums[l] = nums[r];
                l += 1;
            }
            while (l < r && nums[l] < midNum)
            {
                l += 1;
            }
            if (r > l)
            {
                nums[r] = nums[l];
                r -= 1;
            }
        }
        nums[l] = midNum;
        if (l == k)
        {
            return midNum;
        }
        else if (l > k)
        {
            return findKthLargest(nums, left, l - 1, k);
        }
        else
        {
            return findKthLargest(nums, l + 1, right, k);
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
    for (int i = 1; i <= nums.size(); i++)
    {
        cout << s.findKthLargest(nums, i) << endl;
    }
}