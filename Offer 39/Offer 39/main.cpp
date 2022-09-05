#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int num : nums)
        {
            if (count > nums.size() / 2)
            {
                return candidate;
            }
            else if (count == 0)
            {
                candidate = num;
                count = 1;
            }
            else if (num == candidate)
            {
                count += 1;
            }
            else
            {
                count -= 1;
            }
        }
        return candidate;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3,3,4 };
    s.majorityElement(nums);
}
