#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
    long targetLower = 0;
    long targetUpper = 0;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long sum = 0;
        vector<long> preSum;
        preSum.emplace_back(0);
        targetLower = lower;
        targetUpper = upper;
        for (int& num : nums)
        {
            sum += num;
            preSum.emplace_back(sum);
        }
        return mergeSort(preSum,0, nums.size());
    }

    //统计left到mid 和 mid到right两个子区间中满足条件的对数，并进行归并排序
    int mergeSort(vector<long> &preSum,int left, int right)
    {
        if (left == right)
        {
            return 0;
        }
        else
        {
            //归并排序
            int ans = 0;
            int mid = (left + right) / 2;
            ans += mergeSort(preSum,left, mid);
            ans += mergeSort(preSum,mid + 1, right);

            //首先统计对数
            //mid-right中的两个索引
            int index1 = mid+1;
            int index2 = mid+1;
            long nextLower = 0;
            long nextUpper = 0;
            for (int i = left; i <= mid; i++)
            {
                nextLower = preSum[i] + targetLower;
                nextUpper = preSum[i] + targetUpper;
                while (index1 <= right && preSum[index1] <= nextUpper)
                {
                    index1 += 1;
                }

                while (index2 <= right && preSum[index2] < nextLower)
                {
                    index2 += 1;
                }
                ans += index1 - index2;
            }

            //归并排序
            index1 = left;
            index2 = mid + 1;
            vector<long> temp = vector<long>(right-left+1);
            for (int i = 0; i < temp.size(); i++)
            {
                if (index1 > mid)
                {
                    temp[i] = preSum[index2];
                    index2 += 1;
                }
                else if (index2 > right)
                {
                    temp[i] = preSum[index1];
                    index1 += 1;
                }
                else
                {
                    if (preSum[index1] < preSum[index2])
                    {
                        temp[i] = preSum[index1];
                        index1 += 1;
                    }
                    else
                    {
                        temp[i] = preSum[index2];
                        index2 += 1;
                    }
                }
            }
            for (int i = 0; i < temp.size(); i++)
            {
                preSum[left + i] = temp[i];
            }
            return ans;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = { -2,5,-1 };
    cout << s.countRangeSum(nums, -2, 2) << endl;
}