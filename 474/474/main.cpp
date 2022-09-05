#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp;
        for (int i = 0; i <= m; i++)
        {
            dp.emplace_back(n + 1, 0);
        }
        int num1 = 0;
        int num0 = 0;
        for (string str : strs)
        {
            num1 = 0;
            num0 = 0;
            for (char c : str)
            {
                if (c == '0')
                {
                    num0 += 1;
                }
                else
                {
                    num1 += 1;
                }
            }
            for (int i = m; i >= num0; i--)
            {
                for (int j = n; j >= num1; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
        }
        return dp.back().back();
    }
};

int main()
{
    Solution s;
    vector<string> strs = { "10","001", "111001", "1", "0" };
    cout << s.findMaxForm(strs, 5, 3) << endl;
}
