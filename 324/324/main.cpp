#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    int findKthNum(vector<int>& nums, int k) {
        return findKthNum(nums, 0, nums.size() - 1, k);
    }

    int findKthNum(vector<int>& nums, int left, int right, int k) {
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
            return findKthNum(nums, left, l - 1, k);
        }
        else
        {
            return findKthNum(nums, l + 1, right, k);
        }
    }
public:
    void wiggleSort(vector<int>& nums) {
    }
    /*
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int x = (n + 1) / 2;
        int mid = x - 1;
        vector<int> temple = vector<int>(nums);
        findKthNum(temple, mid);
        int right = mid - 1;
        int left = 0;

        while (right > left)
        {
            while (left < right && temple[left] < temple[mid])
            {
                left += 1;
            }
            while (right > left && temple[right] == temple[mid])
            {
                right -= 1;
            }
            if (left < right)
            {
                temple[left] = temple[right];
                temple[right] = temple[mid];
            }
            left += 1;
            right -= 1;
        }

        left = mid + 1;
        right = n - 1;
        while (right > left)
        {
            while (right > left && temple[right] > temple[mid])
            {
                right -= 1;
            }
            while (left < right && temple[left] == temple[mid])
            {
                left += 1;
            }
            if (left < right)
            {
                temple[right] = temple[left];
                temple[left] = temple[mid];
            }
            left += 1;
            right -= 1;
        }

        left = 0;
        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    nums[n - i - 1] = temple[left + x];
                }
                else
                {
                    nums[n - i - 1] = temple[left];
                    left += 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    nums[n - i - 1] = temple[left];
                }
                else
                {
                    nums[n - i - 1] = temple[left + x];
                    left += 1;
                }
            }
        }
    }*/
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,2,1,2,2,1 };
    s.wiggleSort(nums);
    cout << 1 << endl;
}