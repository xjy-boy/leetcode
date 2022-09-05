#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums)
        {
            if (set.count(num)) 
            {
                return num;
            }
            set.insert(num);
        }
        return 0;
    }
};