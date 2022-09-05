#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quikSort(arr, 0, arr.size() - 1, k);
        vector<int> ans;
        ans.assign(arr.begin(), arr.begin() + k);
        return ans;
    }

    void quikSort(vector<int>& arr, int start,int end,int k)
    {
        if (start == end)
        {
            return;
        }
        int mid = arr[start];
        int left = start;
        int right = end;
        while (left < right)
        {
            while (left < right && arr[right] >  mid)
            {
                right -= 1;
            }
            if (left < right)
            {
                arr[left] = arr[right];
                left += 1;
            }
            while (left < right && arr[left] <= mid)
            {
                left += 1;
            }
            if (left < right)
            {
                arr[right] = arr[left];
                right -= 1;
            }
        }

        arr[left] = mid;
        if (left == k -1)
        {
            return;
        }
        else if(left < k-1)
        {
            quikSort(arr,left + 1, end, k);
        }
        else
        {
            quikSort(arr, start, left-1, k);
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr = { 0, 0, 1, 2, 4, 2, 2, 3, 1, 4 };
    s.getLeastNumbers(arr, 8);
}