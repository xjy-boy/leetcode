#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    int ans;
public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }

    void mergeSort(vector<int>& nums, int start, int end)
    {
        if (end == start)
        {
            return;
        }

        int mid = (end + start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, end);
    }

    void merge(vector<int>& nums, int start,int end)
    {
        int mid = (end + start) / 2;
        int p1 = 0;
        int p2 = mid + 1 - start;
        int pend1 = mid - start;
        int pend2 = end - start;
        int p = start;
        vector<int> temple = vector<int>();
        temple.assign(nums.begin() + start, nums.begin() + end + 1);
        while (p1 <= pend1 && p2 <= pend2)
        {
            if (temple[p2] < temple[p1])
            {
                ans += pend1 - p1 + 1;
                nums[p] = temple[p2];
                p2 += 1;
                p += 1;
            }
            else
            {
                nums[p] = temple[p1];
                p1 += 1;
                p += 1;
            }
        }

        while (p1 <= pend1)
        {
            nums[p] = temple[p1];
            p1 += 1;
            p += 1;
        }

        while (p2 <= pend2)
        {
            nums[p] = temple[p2];
            p2 += 1;
            p += 1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 7,5,6,4 };
    cout << s.reversePairs(nums) << endl;
}