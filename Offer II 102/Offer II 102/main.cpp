#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        vector<vector<int>> dp = vector<vector<int>>();
        dp.push_back(vector<int>(sum * 2 + 1, 0));
        dp.push_back(vector<int>(sum * 2 + 1, 0));
        //±ß½çÌõ¼þ
        set<int> s = set<int>();
        s.insert(0);
        for (int i = 0; i < nums.size(); i++)
        {
            set<int> temple = set<int>();
            for (int j = 0; j < s.size(); j++)
            {
                dp[s[j]]
            }
        }
    }
};

int main()
{

}