#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> kStack;
        int kMax = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < kMax)
            {
                return true;
            }
            while (!kStack.empty() && nums[i] > kStack.top()) {
                kMax = kStack.top();
                kStack.pop();
            }
            kStack.push(nums[i]);
        }

        return false;
    }
};