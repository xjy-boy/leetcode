#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string result = "";
        result += to_string(nums[0]);
        if (nums.size() == 2)
        {
            result += "/";
            result += to_string(nums[1]);
        }
        else if(nums.size() > 2)
        {
            result += "/(";
            for (int i = 1; i < nums.size() - 1; i++)
            {
                result += to_string(nums[i]);
                result += "/";
            }
            result += to_string(nums[nums.size() - 1]);
            result += ")";
        }
        return result;
    }
};

int main()
{
    vector<int> nums = { 1000,100,10,2 };
    Solution s;
    cout << s.optimalDivision(nums) << endl;
}