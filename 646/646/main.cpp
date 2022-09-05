#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp = [&](const vector<int>& p1, const vector<int>& p2) {
            if (p1[0] == p2[0])
            {
                return p1[1] > p2[1];
            }
            else
            {
                return p1[0] < p2[0];
            }
        };

        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp = vector<int>(pairs.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < pairs.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (pairs[i][0] > pairs[j][1])
                {
                    dp[i] = dp[j] + 1;
                    break;
                }
            }
        }

        return dp.back();
    }
};

int main()
{
    Solution s;
    vector<vector<int>> p = {
        {1,2},
        {1,3},
        {2,3},
        {3,4}
    };
    cout << s.findLongestChain(p) << endl;
}