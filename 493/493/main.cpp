#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
    int ans = 0;
    vector<int> t;
public:
    int reversePairs(vector<int>& nums) {
        t = vector<int>(nums.size(), 0);
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }

    void mergeSort(vector<int>& nums,int left, int right) {
        if (left == right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int index = left;
        int index1 = left;
        int index2 = mid + 1;
        for (int i = mid + 1; i <= right; i++)
        {
            if (INT_MAX / 2 < nums[i])
            {
                break;
            }
            else if (INT_MIN / 2 > nums[i])
            {
                ans += mid + 1 -  left;
            }
            else
            {
                auto it = upper_bound(nums.begin() + left, nums.begin() + mid + 1, nums[i] * 2);
                ans += nums.begin() + mid + 1 - it;
            }
        }
        while (index1 <= mid
            && index2 <= right)
        {
            if (nums[index1] <= nums[index2])
            {
                t[index] = nums[index1];
                index += 1;
                index1 += 1;
            }
            else if(nums[index1] > nums[index2])
            {
                t[index] = nums[index2];
                index += 1;
                index2 += 1;
            }
        }

        while (index1 <= mid)
        {
            t[index] = nums[index1];
            index += 1;
            index1 += 1;
        }
        while (index2 <= right)
        {
            t[index] = nums[index2];
            index += 1;
            index2 += 1;
        }
        for (int i = left; i <= right; i++)
        {
            nums[i] = t[i];
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {
        2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647
    };
    cout << s.reversePairs(nums) << endl;
}