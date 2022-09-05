#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int index = k;
        ans = sum;
        while (index < nums.size())
        {
            sum = sum - nums[index - k] + nums[index];
            ans = max(sum, ans);
            index += 1;
        }
        return (double)ans / (double)k;
    }
};