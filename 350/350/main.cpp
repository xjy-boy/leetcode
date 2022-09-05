#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> numCount = vector<int>(1001, 0);
        for (int num : nums1)
        {
            numCount[num] += 1;
        }

        for (int num : nums2)
        {
            if (numCount[num] > 0)
            {
                ans.emplace_back(num);
                numCount[num] -= 1;
            }
        }
        return ans;
    }
};