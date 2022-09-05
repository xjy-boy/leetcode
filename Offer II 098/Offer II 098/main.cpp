#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp = vector<int>(m,1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[j] += dp[j - 1];
            }
        }
        return dp[m - 1];
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3, 3) << endl;
}