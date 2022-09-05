#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({ nums[0] });
        for (int i = 1; i < nums.size(); i++)
        {
            int now = result.size();
            for (int j = 0; j < now; j++)
            {
                for (int k = 0; k < i; k++)
                {
                    result.push_back(result[j]);
                    result.back().insert(result.back().begin() + k, nums[i]);
                }
                result[j].push_back(nums[i]);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = { 1,2,3 };
    Solution s;
    s.permute(nums);
}