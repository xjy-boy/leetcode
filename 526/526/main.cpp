#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> dp;
    vector<int> symbol;
    int num = 0;
    int countArrangement(int n) {
        if (n == 0)
        {
            return 0;
        }
        int t = 1;
        num = n;
        symbol.emplace_back(0);
        for (int i = 0; i < n; i++)
        {
            symbol.emplace_back(t);
            t = t << 1;
        }
        dp = vector<int>(pow(2, n), -1);
        dp[0] = 1;
        return dfs(dp.size() - 1, n);
    }

    int dfs(int mask,int now)
    {
        if (dp[mask] < 0)
        {
            dp[mask] = 0;
            for (int i = 1; i <= num; i++)
            {
                if (mask & symbol[i])
                {
                    if (i % now == 0 || now % i == 0)
                    {
                        dp[mask] += dfs(mask ^ symbol[i], now - 1);
                    }
                }
            }
        }
        return dp[mask];
    } 
};

int main()
{
    for (int i = 0; i <= 15; i++)
    {
        Solution s;
        cout << s.countArrangement(i) << endl;
    }
}