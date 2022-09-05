#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto start = lower_bound(nums.begin(), nums.end(), target);
        if (start == nums.end() || *start != target)
        {
            return 0;
        }
        auto end = upper_bound(start, nums.end(), target);
        return end - start;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 5,7,7,8,8,10 };
    cout << s.search(nums, 10) << endl;
}