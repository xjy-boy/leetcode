#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> data;
    int target = 0;
public:
    int findKthLargest(vector<int>& nums, int k) {
        data = nums;
        target = nums.size() - k;
        return quikSort(0, nums.size() - 1);
    }

    int quikSort(int start,int end)
    {
        int left = start;
        int right = end;
        while (left < right)
        {
            while (right > left && data[right] > data[start])
            {
                right -= 1;
            }
            while (left < right && data[left] <= data[start])
            {
                left += 1;
            }
            int t = data[left];
            data[left] = data[right];
            data[right] = t;
        }
        int t = data[left];
        data[left] = data[start];
        data[start] = t;
        int result = 0;
        if (left == target)
        {
            result = data[left];
        }
        else if (left > target)
        {
            result = quikSort(start, left - 1);
        }
        else
        {
            result = quikSort(left + 1, end);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
    int k = 4;
    cout << s.findKthLargest(nums, k) << endl;
}