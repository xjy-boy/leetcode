#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    vector<vector<int>> dp;
public:
    int getMoneyAmount(int n) {
        for (int i = 0; i <= n + 1; i++)
        {
            dp.emplace_back(n + 2, 0);
        }
        /*
        for (int i = 0; i <= n; i++)
        {
            dp[i][i] = 0;
        }
        return backSearch(1, n);
        */
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                dp[j][i] = INT_MAX;
                for (int k = j; k <= i; k++)
                {
                    dp[j][i] = min(dp[j][i],
                        k + max(dp[j][k - 1], dp[k + 1][i]));
                }
            }
        }
        return dp[1][n];
    }

    int backSearch(int left, int right)
    {
        if (left > right)
        {
            return 0;
        }
        else if (dp[left][right] < 0)
        {
            int ans = INT_MAX;
            for (int i = left; i <= right; i++)
            {
                ans = min(ans,i + max(backSearch(left, i - 1), backSearch(i + 1, right)));
            }
            dp[left][right] = ans;
            return ans;
        }
        else
        {
            return dp[left][right];
        }
    }
};

int main()
{
    Solution s;
    cout << s.getMoneyAmount(10) << endl;
}