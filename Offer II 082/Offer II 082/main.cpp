#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temple;
    vector<int> nums;
    vector<int> numCount;
    int sum = 0;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        numCount =vector<int>(51, 0);
        sum = 0;
        for (int num : candidates)
        {
            if (numCount[num] == 0)
            {
                nums.push_back(num);
            }
            numCount[num] += 1;
        }

        
        sum = 0;
        result.clear();
        temple.clear();
        dfs(0, target);
        return result;
    }

    void dfs(int nowIndex,int target)
    {
        int length = temple.size();
        int oldSum = sum;
        for(int i = 0; i <numCount[nums[nowIndex]];i++)
        {
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
            else
            {
                if (nowIndex < nums.size() - 1)
                {
                    dfs(nowIndex + 1, target);
                }
            }
        }
        temple.erase(temple.begin() + length, temple.end());
        sum = oldSum;
        if (nowIndex < nums.size() - 1)
        {
            dfs(nowIndex + 1, target);
        }
    }
};

int main()
{
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    int target = 8;
    Solution s;
    s.combinationSum2(candidates, target);
}