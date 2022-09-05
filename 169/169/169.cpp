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
                break;
            }
            else if (count == 0)
            {
                candidate = num;
                count = 1;
            }
            else
            {
                if (candidate == num)
                {
                    count += 1;
                }
                else
                {
                    count -= 1;
                }
            }
        }
        return candidate;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,2,1,1,1,2,2, };
    cout << s.majorityElement(nums) << endl;
}