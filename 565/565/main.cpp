#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        int index = 0;
        int length = 0;
        int next = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            index = i;
            length = 0;
            while (nums[index] >= 0)
            {
                length += 1;
                next = nums[index];
                nums[index] = -1;
                index = next;
            }
            ans = max(ans, length);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 5,4,0,3,1,6,2 };
    cout << s.arrayNesting(nums) << endl;
}