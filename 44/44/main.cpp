#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> minLength;
public:
    bool isMatch(string s, string p) {
        if (p.empty())
        {
            return s.empty();
        }
        else if (p.size() == 1)
        {
            if (p[0] == '*')
            {
                return true;
            }
            else
            {
                return s.size() == 1 && (p[0] == '?' || s[0] == p[0]);
            }
        }
        //对p预处理，删除连续的*
        for (int i = 1; i < p.size(); i++)
        {
            if (p[i] == '*' && p[i - 1] == '*')
            {
                p.erase(i,1);
                i -= 1;
            }
        }
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }

};

int main()
{
    Solution solution;
    string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    cout << solution.isMatch(s, p) << endl;
}