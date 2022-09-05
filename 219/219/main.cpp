#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> numSet;
        if (k > nums.size())
        {
            k = nums.size();
        }
        for (int i = 0; i < k; i++)
        {
            if (numSet.count(nums[i]))
            {
                return true;
            }
            numSet.insert(nums[i]);
        }
        for (int i = k; i < nums.size();i++)
        {
            if (numSet.count(nums[i]))
            {
                return true;
            }
            numSet.insert(nums[i]);
            numSet.erase(nums[i - k]);
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    s.containsNearbyDuplicate(nums, 15);
}