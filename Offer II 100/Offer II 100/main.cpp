#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = vector<vector<int>>();
        dp.push_back(vector<int>(triangle.size()));
        dp.push_back(vector<int>(triangle.size()));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++)
        {
            int index = i % 2;
            dp[index][0] = dp[1 - index][0] + triangle[i][0];
            dp[index][i] = dp[1 - index][i - 1] + triangle[i][i];
            for (int j = 1; j < i; j++)
            {
                dp[index][j] = min(dp[1 - index][j], dp[1 - index][j - 1]) + triangle[i][j];
            }

        }

        int index = 1 - triangle.size() % 2;
        int ans = INT_MAX;
        for (int num : dp[index])
        {
            if (num < ans)
            {
                ans = num;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << s.minimumTotal(triangle) << endl;
}