#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp = vector<int>(s.size(), 0);
        if (s[0] == '0')
        {
            return 0;
        }
        dp[0] = 1;
        if (s.size() == 1)
        {
            return 1;
        }
        else
        {
            if (s[1] == '0')
            {
                if (s[0] != '1' && s[0] != '2')
                {
                    return 0;
                }
                else
                {
                    dp[1] = 1;
                }
            }
            else if (s[0] == '1' || (s[0] == '2' && s[1] <= '6'))
            {
                dp[1] = 2;
            }
            else
            {
                dp[1] = 1;
            }
        }
        for (int i = 2; i < s.size(); i++)
        {
            
            if (s[i] == '0')
            {
                if (s[0] != '1' && s[0] != '2')
                {
                    return 0;
                }
                else
                {
                    dp[i] = dp[i - 2];
                }
            }
            else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
            {
                dp[i] = dp[i-1] + dp[i-2];
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[s.size() - 1];
    }
};

int main()
{
    Solution solution;
    string s = "01231231";
    cout << solution.numDecodings(s) << endl;
}