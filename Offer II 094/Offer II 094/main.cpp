#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    vector<vector<string>> ans;
    vector<string> now;
public:
    int minCut(string s) {
        vector<vector<int>> index = manacher(s);
        vector<int> dp = vector<int>(s.length(), INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < s.length(); i++)
        {
            for (int leftIndex : index[i])
            {
                if (leftIndex == 0)
                {
                    dp[i] = 0;
                    break;
                }
                dp[i] = min(dp[leftIndex - 1] + 1, dp[i]);
            }
        }
        return dp[s.length() - 1];
    }

    vector<vector<int>> manacher(string s)
    {
        string templeS = "#";
        for (char c : s)
        {
            templeS += c;
            templeS += '#';
        }
        vector<vector<int>> index = vector<vector<int>>(s.size());
        int maxi = 1;
        int maxLeft = 2;
        for (int i = 1; i < templeS.length(); i++)
        {
            int nowLength = 1;
            while (i + nowLength < templeS.length() && i - nowLength >= 0)
            {
                if (templeS[i + nowLength] == templeS[i - nowLength])
                {
                    nowLength += 1;
                }
                else
                {
                    break;
                }
                int rightIndex = i + nowLength - 1;
                int leftIndex = i - nowLength + 1;
                if (leftIndex == 0)
                {
                    index[rightIndex / 2 - 1].clear();
                    index[rightIndex / 2 - 1].emplace_back(0);
                }
                else if (!index[rightIndex / 2 - 1].empty() && index[rightIndex / 2 - 1][0] == 0)
                {
                    continue;
                }
                else if (leftIndex % 2 == 0)
                {
                    index[rightIndex / 2 -1].emplace_back(leftIndex / 2);
                }
            }
            int a = 1;
        }
        return index;
    }
};

int main()
{
    Solution solution;
    string s = "aab";
    cout << solution.minCut(s) << endl;
}