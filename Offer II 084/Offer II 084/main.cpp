#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    vector<int> numCount;
    vector<vector<int>> result;
    vector<int> temple;
    vector<int> nums;
    int max = 0;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        temple.clear();
        result.clear();
        max = nums.size();
        numCount = vector<int>(21, 0);
        for (int num : nums)
        {
            if (numCount[num + 10] == 0)
            {
                this->nums.push_back(num);
            }
            numCount[num + 10] += 1;
        }
        backtrack(0);
        return result;
    }
    void backtrack(int nowIndex) {
        if (nowIndex == max)
        {
            result.emplace_back(temple);
            return;
        }
        for (int num : nums)
        {
            if (numCount[num + 10] == 0)
            {
                continue;
            }
            else
            {
                temple.emplace_back(num);
                numCount[num + 10] -= 1;
                backtrack(nowIndex + 1);
                numCount[num + 10] += 1;
                temple.pop_back();
            }
        }
    }
};

int main()
{
    vector<int> nums = { 1,1,2 };
    Solution s;
    s.permuteUnique(nums);
}