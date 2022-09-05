#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> dp = vector<int>(n, 0);
        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (dp[i] < 0)
            {
                continue;
            }
            else
            {
                ans += 1;
                if (n / i >= i)
                {
                    int next = i * i;
                    while (next < n)
                    {
                        dp[next] = -1;
                        next += i;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.countPrimes(10) << endl;
}