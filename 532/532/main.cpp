#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
        {
            return 0;
        }
        unordered_set<int> numSet;
        unordered_set<int> ansSet;
        for (int& num : nums)
        {
            if (numSet.count(num + k))
            {
                ansSet.insert(num + k);
            }
            if (numSet.count(num - k))
            {
                ansSet.insert(num);
            }
            numSet.insert(num);
        }
        return ansSet.size();
    }
};

int main()
{
    Solution s;
    vector<int> nums = {
        6,3,5,7,2,3,3,8,2,4
    };
    cout << s.findPairs(nums, 2) << endl;
}