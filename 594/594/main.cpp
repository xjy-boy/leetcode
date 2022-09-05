#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        int ans = 0;
        for (int num : nums)
        {
            if (count.count(num))
            {
                count[num] += 1;
            }
            else
            {
                count[num] = 1;
            }

            if (count.count(num - 1))
            {
                ans = max(ans, count[num] + count[num - 1]);
            }

            if (count.count(num + 1))
            {
                ans = max(ans, count[num] + count[num + 1]);
            }
        }
        return ans;
    }
};
