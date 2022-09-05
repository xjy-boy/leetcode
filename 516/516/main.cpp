#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
public:
    int longestPalindromeSubseq(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            dp.emplace_back(s.size(), -1);
        }
        return dfs(s, 0, s.size() - 1);
    }

    int dfs(string &s,int left, int right)
    {
        if (left > right)
        {
            return 0;
        }
        else if (dp[left][right] > 0)
        {
            return dp[left][right];
        }
        else if (left == right)
        {
            return 1;
        }

        int ans = 1;
        if (s[left] == s[right])
        {
            ans = max(ans, dfs(s, left + 1, right - 1) + 2);
        }
        else
        {
            ans = max(ans, dfs(s, left, right - 1));
            ans = max(ans, dfs(s, left + 1, right));
        }
        dp[left][right] = ans;
        return ans;
    }
};