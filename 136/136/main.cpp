#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums)
        {
            ans = ans ^ num;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,4,4,5,5 };
    cout << s.singleNumber(nums) << endl;
}