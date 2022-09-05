#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets == 1)
        {
            return 0;
        }
        else if (buckets == 2)
        {
            return 1;
        }

        //dp[j][i]表示i个猪做j次实验可以检测出的最多数量
        //边界点：dp[0][i] = log(i),dp[i]
        //对于dp[i][j]的第一次实验，可以分为以下情况：
        //1.没有猪被毒死，此时可以检测dp[i][j-1]个桶
        //2.有一个猪被毒死，此时剩下猪可以检测dp[i-1][j-1]个桶，因此每个猪都可以检测dp[i-1][j-1]个桶
        //3.有两个猪被毒死，此时剩下猪可以检测dp[i-2][j-1]个桶，因此每两个猪都可以检测此时剩下猪可以检测dp[i-1][j-1]个桶
        //...
        //i.所有猪被毒死，此时没有剩余猪，因此所有猪都喝的桶只能有一个。
        int t = minutesToTest / minutesToDie;
        vector<vector<int>> dp = vector<vector<int>>(t, vector<int>());
        //边界条件,只做一次实验
        int nextBuckets = 1;
        while (nextBuckets < buckets)
        {
            dp[0].emplace_back(nextBuckets);
            nextBuckets = nextBuckets << 1;
        }
        dp[0].emplace_back(nextBuckets);
        //
        int num = 1;
        int pig = 0;
        for (int i = 1; i < t; i++)
        {
            //0头猪只能检测一个桶
            dp[i].push_back(1);
            while (dp[i].back() < buckets)
            {
                nextBuckets = 0;
                num = 1;
                pig = dp[i].size();
                //毒死数量从0到所有
                for (int j = 0; j <= dp[i].size(); j++)
                {
                    if (j != 0)
                    {
                        num = num * (pig - j + 1) / j;
                    }
                    //num为组合数，dp[i-1][pig-j]为剩下的猪
                    nextBuckets += num * dp[i - 1][pig - j];
                }
                dp[i].emplace_back(nextBuckets);
            }
        }
        return dp[t - 1].size() - 1;
    }
};

int main()
{
    Solution s;
    cout << s.poorPigs(25, 15, 60) << endl;
}