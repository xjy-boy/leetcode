#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp = vector<int>(n, 0);
        dp[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        int next2 = dp[p2] * 2;
        int next3 = dp[p3] * 3;
        int next5 = dp[p5] * 5;
        for (int i = 1; i < n; i++)
        {
            dp[i] = min(min(next2, next3), next5);
            if (dp[i] == next2)
            {
                p2 += 1;
                next2 = dp[p2] * 2;
            }
            if (dp[i] == next3)
            {
                p3 += 1;
                next3 = dp[p3] * 3;
            }
            if (dp[i] == next5)
            {
                p5 += 1;
                next5 = dp[p5] * 5;
            }
        }
        return dp.back();
    }
};


int main()
{
    Solution s;
    //s.nthUglyNumber(6);
    for (int i = 0; i < 18; i++)
    {
        cout << s.nthUglyNumber(i + 1) << endl;
        //cout << s.test(i + 1) << endl;
    }
}