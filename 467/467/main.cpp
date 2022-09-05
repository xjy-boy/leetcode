#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp = vector<int>(26, 0);
        char pre = ' ';
        int preLength = 1;
        for (char c : p)
        {
            if (c - pre == 1 || c - pre == -25)
            {
                preLength += 1;
            }
            else
            {
                preLength = 1;
            }
            dp[c - 'a'] = max(dp[c - 'a'], preLength);
            pre = c;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans += dp[i];
        }
        return ans;
    }
};