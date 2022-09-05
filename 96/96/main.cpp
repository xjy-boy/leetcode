#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp = vector<int>(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int ans = 0;
            for (int j = 0; j < i; j++)
            {
                ans += dp[j] * dp[i - j - 1];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    for (int i = 1; i < 10; i++)
    {
        cout << s.numTrees(i) << endl;
    }
}