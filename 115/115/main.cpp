#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || s.size() < t.size())
        {
            return 0;
        }
        else if (s.size() == t.size())
        {
            return s == t;
        }
        vector<vector<int>> dp;
        dp.push_back(vector<int>(s.size(), 0));
        dp.push_back(vector<int>(s.size(), 1));

        //±ß½çÌõ¼þ
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == t[0])
            {
                sum += 1;
            }
            dp[0][i] = sum;
        }

        int nowIndex = 0;
        int preIndex = 0;
        for (int i = 1; i < t.size(); i++)
        {
            nowIndex = i % 2;
            preIndex = 1 - nowIndex;
            sum = 0;
            dp[nowIndex][0] = 0;
            for (int j = 1; j < s.size(); j++)
            {
                if (t[i] == s[j])
                {
                    sum += dp[preIndex][j - 1];
                }
                dp[nowIndex][j] = sum;
            }
        }
        return dp[nowIndex][s.size() - 1];
    }
};

int main()
{
    Solution solution;
    string s = "babgbag";
    string t = "bag";
    cout << solution.numDistinct(s,t) << endl;
}