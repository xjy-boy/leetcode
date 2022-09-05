#include<iostream>
#include<vector>
#include<stack>


using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int ans = INT_MIN;
        for (int num : nums)
        {
            pre = max(num, pre + num);
            if (pre > ans)
            {
                ans = pre;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << s.maxSubArray(arr) << endl;
}