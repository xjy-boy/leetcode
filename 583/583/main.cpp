#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    //dp[i][j]表示word1[0-i]和word[0-j]需要的变化次数
    vector<vector<int>> dp;
    
    int minDistance(string word1, string word2){
        for (int i = 0; i < word1.size() + 1; i++)
        {
            dp.emplace_back(word2.size() + 1, -1);
        }
        for (int i = 0; i < word1.size() + 1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i < word2.size() + 1; i++)
        {
            dp[0][i] = i;
        }
        return dfs(word1, word2, word1.size(), word2.size());
    }

    int dfs(string& word1, string& word2, int index1, int index2)
    {
        if (dp[index1][index2] < 0)
        {
            if (word1[index1 - 1] == word2[index2 - 1])
            {
                dp[index1][index2] = dfs(word1, word2, index1 - 1, index2 - 1);
                dp[index1][index2] = min(dp[index1][index2],
                    dfs(word1, word2, index1 - 1, index2) + 1);
                dp[index1][index2] = min(dp[index1][index2],
                    dfs(word1, word2, index1, index2 - 1) + 1);
            }
            else
            {
                dp[index1][index2] = min(
                    dfs(word1, word2, index1 - 1, index2),
                    dfs(word1, word2, index1, index2 - 1)) + 1;
            }
        }
        return dp[index1][index2];
    }
};

int main()
{
    Solution s;
    string s1 = "sea";
    string s2 = "eat";
    cout << s.minDistance(s1, s2) << endl;
}