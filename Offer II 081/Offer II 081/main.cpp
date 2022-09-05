#include<vector>
#include<iostream>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> nums;
    vector<int> temple;
    int sum = 0;
    int target = 0;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        nums = vector<int>(candidates);
        result.clear();
        temple.clear();
        this->target = target;
        dfs(0);
        return result;
    }

    void dfs(int nowIndex)
    {
        if (nowIndex >= nums.size())
        {
            return;
        }
        int length = temple.size();
        int oldSum = sum;
        while (true)
        {
            dfs(nowIndex + 1);
            temple.push_back(nums[nowIndex]);
            sum += nums[nowIndex];
            if (sum == target)
            {
                result.push_back(temple);
                break;
            }
            else if (sum > target)
            {
                break;
            }
        }
        temple.erase(temple.begin() + length, temple.end());
        sum = oldSum;
    }
};

int main()
{
    vector<int> candidates = { 2,3,6,7 };
    int target = 7;
    Solution s;
    s.combinationSum(candidates,target);
}