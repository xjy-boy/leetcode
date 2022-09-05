#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int row = grid.size();
        int rol = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < rol; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans += 4;
                    if (i != 0 && grid[i - 1][j] == 1)
                    {
                        ans -= 2;
                    }

                    if (j != 0 && grid[i][j - 1] == 1)
                    {
                        ans -= 2;
                    }
                }
            }
        }
        return ans;
    }
};
