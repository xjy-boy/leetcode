#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        for (int& num : nums)
        {
            sum = sum + num;
        }
        sort(nums.rbegin(), nums.rend());
        vector<int> ans;
        int ansSum = 0;
        sum = sum / 2;
        for (int& num : nums)
        {
            ans.emplace_back(num);
            ansSum += num;
            if (ansSum > sum)
            {
                break;
            }
        }
        return ans;
    }
};