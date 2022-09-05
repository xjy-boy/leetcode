#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s3.size() != s1.size() + s2.size())
        {
            return false;
        }
        if (s1.size() < s2.size())
        {
            string temple = s2;
            s2 = s1;
            s1 = temple;
        }
        vector<vector<bool>> dp = vector<vector<bool>>();
        for (int i = 0; i < s2.size() + 1; i++)
        {
            dp.emplace_back(vector<bool>(s1.size() + 1, false));
        }
        dp[0][0] = true;
        int length1 = s1.size();
        int length2 = s2.size();
        for (int i = 0; i < s3.size(); i++)
        {
            int row = max(0, i - length1 + 1);
            int rol = min(length1, i + 1);
            while (rol >=  0 && row <= length2)
            {
                if (rol >0 && s3[i] == s1[rol - 1])
                {
                    if (dp[row][rol - 1])
                    {
                        dp[row][rol] = true;
                        rol -= 1;
                        row += 1;
                        continue;
                    }
                }

                if (row > 0 && s3[i] == s2[row - 1])
                {
                    if (dp[row - 1][rol])
                    {
                        dp[row][rol] = true;
                        rol -= 1;
                        row += 1;
                        continue;
                    }
                }
                rol -= 1;
                row += 1;
            }
        }
        return dp[length1][length2];
    }
};

int main()
{
    Solution solution;
    string s1 = "aabc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";
    //solution.isInterleave(s1, s2, s3);
    solution.isInterleave("a", "", "a");
}