#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int index = 0;
        while (index < nums.size())
        {
            ans += nums[index];
            index += 2;
        }
        return ans;
    }
};