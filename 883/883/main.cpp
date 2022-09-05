#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans1 = 0;
        int ans2 = 0;

        vector<int> ans3 = vector<int>(n, 0);
        for (int i = 0; i < n; i++)
        {
            int maxRow = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    ans1 += 1;
                    maxRow = max(maxRow, grid[i][j]);
                    ans3[j] = max(ans3[j], grid[i][j]);
                }
            }
            ans2 += maxRow;
        }

        int ans = 0;
        for (int num : ans3)
        {
            ans += num;
        }
        return ans + ans1 + ans2;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {2}
    };
    Solution s;
    s.projectionArea(grid);
}