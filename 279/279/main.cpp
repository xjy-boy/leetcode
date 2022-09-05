#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> dp;
public:
    int numSquares(int n) {
        dp = vector<int>(n + 1, -1);
        dp[0] = 0;
        return getResult(n);
    }

    int getResult(int n) {
        if (dp[n] >= 0)
        {
            return dp[n];
        }
        else
        {
            int t = sqrt(n);
            int result = INT_MAX;
            for (int i = 1; i <= t; i++)
            {
                result = min(result, getResult(n - i * i));
            }
            dp[n] = result + 1;
            return dp[n];
        }
    }
};

int main()
{
    Solution s;
    cout << s.numSquares(13) << endl;
}