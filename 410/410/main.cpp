#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = 0;
        for (int& num : nums)
        {
            if (num > left)
            {
                left = num;
            }
            right += num;
        }
        
        int count = 0;
        int maxSum = 0;
        int sum = 0;
        int mid = 0;

        //���ֲ���
        while (left < right)
        {
            mid = (left + right) / 2;

            //���mid�Ƿ����Ҫ��
            count = 1;
            sum = 0;
            maxSum = 0;
            for (int& num : nums)
            {
                if (sum + num> mid)
                {
                    maxSum = max(sum, maxSum);
                    sum = num;
                    count += 1;
                    if (count > m)
                    {
                        break;
                    }
                }
                else
                {
                    sum += num;
                }
            }
            maxSum = max(sum, maxSum);
            //��ǰmid��С
            if (count > m)
            {
                left = mid + 1;
            }
            else
            {
                right = maxSum;
            }
        }
        return left;
    }
};