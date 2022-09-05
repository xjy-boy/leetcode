#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < m; i++)
        {
            nums1[m + n - 1 - i] = nums1[m - 1 - i];
        }
        int index1 = n;
        int index2 = 0;
        int index = 0;
        while (index1 < m + n && index2 < n)
        {
            if (nums1[index1] < nums2[index2])
            {
                nums1[index] = nums1[index1];
                index1 += 1;
            }
            else
            {
                nums1[index] = nums2[index2];
                index2 += 1;
            }
            index += 1;
        }
        while (index1 < m + n)
        {
            nums1[index] = nums1[index];
            index1 += 1;
            index += 1;
        }

        while (index2 <n)
        {
            nums1[index] = nums2[index2];
            index2 += 1;
            index += 1;
        }
    }
};

int main()
{
    vector<int> nums1 = {0 };
    int m = 0;
    vector<int> nums2 = { 2};
    int n = 1;
    Solution s;
    s.merge(nums1,m,nums2,n);
}