#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums)
        {
            if (numSet.count(num))
            {
                return true;
            }
            numSet.insert(num);
        }
        return false;
    }
};