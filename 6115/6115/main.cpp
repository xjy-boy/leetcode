#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<int>> factor;
    int mod = 1e9 + 7;
public:
    int idealArrays(int n, int maxValue) {
        
        for (int i = 0; i < n + 1; i++)
        {
            dp.emplace_back(maxValue + 1, -1);
        }
        factor = vector<vector<int>>(maxValue + 1);
        for (int i = 1; i <= maxValue; i++)
        {
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    factor[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= maxValue; i++)
        {
            ans = (ans + dfs(n, i)) % mod;
        }
        return ans;
    }

    int dfs(int n, int maxValue) 
    {
        if (dp[n][maxValue] > 0)
        {
            return dp[n][maxValue];
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (maxValue == 1)
        {
            return 1;
        }
        int ans = n;
        for (int &num:factor[maxValue])
        {
            ans = (ans + dfs(n - 1, num)) % mod;
        }
        dp[n][maxValue] = ans;
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.idealArrays(5, 9) << endl;
}