#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp = vector<int>(n, 0);
        vector<int> p = vector<int>(primes.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int next = INT_MAX;
            for (int j = 0; j < p.size(); j++)
            {
                next = min(next, dp[p[j]] * primes[j]);
            }
            dp[i] = next;
            for (int j = 0; j < p.size(); j++)
            {
                if (dp[p[j]] * primes[j] == next)
                {
                    p[j] += 1;
                }
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution s;
    vector<int> primes = { 2,7,13,19 };
    for (int i = 1; i <= 12; i++)
    {
        cout << s.nthSuperUglyNumber(i, primes) << endl;
    }
}