#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp = vector<long>(n, 0);
        dp[0] = 1;
        for (int i = 1; i < delay; i++)
        {
            dp[i] = 0;
        }
        
        for (int i = delay; i < forget; i++)
        {
            long sum = 0;
            for (int j = i - forget + 1; j <= i - delay; j++)
            {
                if (j < 0)
                {
                    continue;
                }
                sum = (sum + dp[j]) % mod;
            }
            dp[i] = sum;
        }
        int left = 0;
        int right = forget - delay;
        long now = 0;
        for (int i = left; i < right; i++)
        {
            now = (now + dp[i]) % mod;
        }
        //动态规划
        for (int i = forget; i < n; i++)
        {
            now = now - dp[left] + dp[right];
            if (now < 0)
            {
                now = now + mod;
            }
            else
            {
                now = now % mod;
            }
            left += 1;
            right += 1;
            dp[i] = now;
        }

        //计算答案
        long ans = 0;
        for (int i = 1; i <= forget; i++)
        {
            ans = (ans + dp[n - i]) % mod;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.peopleAwareOfSecret(289, 7, 23) << endl;
}