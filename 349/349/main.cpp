#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<bool> numCount = vector<bool>(1001,false);
        for (int num : nums1)
        {
            numCount[num] = true;
        }

        for (int num : nums2)
        {
            if (numCount[num])
            {
                numCount[num] = false;
                ans.emplace_back(num);
            }
        }
        return ans;
    }
};