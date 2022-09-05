#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //pre[i][j]含义为结尾为i，公差为j的序列个数(长度最少为2)
        vector<unordered_map<long, int>> pre;
        pre = vector<unordered_map<long, int>>(nums.size());
        long dif = 0;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            //计算dp[i]与pre[i]
            for (int j = 0; j < i; j++)
            {
                dif = (long)nums[i] - (long)nums[j];
                //之前有序列
                if (pre[j].count(dif))
                {
                    ans += pre[j][dif];
                    if (pre[i].count(dif))
                    {
                        pre[i][dif] += pre[j][dif] + 1;
                    }
                    else
                    {
                        pre[i][dif] = pre[j][dif] + 1;
                    }
                }
                else
                {
                    if (pre[i].count(dif))
                    {
                        pre[i][dif] +=  1;
                    }
                    else
                    {
                        pre[i][dif] =  1;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 7,7,7,7,7 };
    Solution s;
    cout << s.numberOfArithmeticSlices(nums) << endl;
}