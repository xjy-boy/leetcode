#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index1 = 0;
        int index2 = 0;
        int ans = 0;
        int sum = 0;
        for (int i = nums.size()-1; i > 1; i--)
        {
            index2 = i - 1;
            index1 = 0;
            while (index1 < index2)
            {
                sum = nums[index1] + nums[index2];
                if (sum <= nums[i])
                {
                    index1 += 1;
                }
                else if (sum > nums[i])
                {
                    ans += index2 - index1;
                    index2 -= 1;
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = { 2,2,3,4 };
    Solution s;
    cout << s.triangleNumber(nums) << endl;
}