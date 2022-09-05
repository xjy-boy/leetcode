#include<iostream>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = INT_MAX;
        int dp = 0;
        for (char c : s)
        {
            dp += 49 - c;
        }
        if (ans > dp)
        {
            ans = dp;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                dp += 1;
            }
            else
            {
                dp -= 1;
            }
            if (ans > dp)
            {
                ans = dp;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "010110";
    cout << solution.minFlipsMonoIncr(s) << endl;
}