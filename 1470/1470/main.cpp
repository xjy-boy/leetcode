#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans = vector<int>(nums.size());
        int index = 0;
        for (int i = 0; i < n; i ++)
        {
            ans[index] = nums[i];
            ans[index + 1] = nums[i + n];
            index += 2;
        }
        return ans;
    }
};