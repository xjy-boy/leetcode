#include<iostream>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumMap;
        int sum = 0;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                sum = a + b;
                if (sumMap.count(sum)) 
                {
                    sumMap[sum] = sumMap[sum] + 1;
                }
                else
                {
                    sumMap[sum] = 1;
                }
            }
        }

        int ans = 0;
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                sum = - c - d ;
                if (sumMap.count(sum))
                {
                    ans += sumMap[sum];
                }
            }
        }
        return ans;
    }
};