#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    int m = 0;
    int n = 0;
    vector<int> fx;

    int find(int x)
    {
        int p = x;
        while (fx[p] >= 0)
        {
            p = fx[p];
        }
        if (fx[x] > 0)
        {
            fx[x] = p;
        }
        return p;
    }

    bool join(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
        {
            return false;
        }
        else
        {
            fx[py] = px;
            return true;
        }
    }

    int getIndex(int row, int column)
    {
        return row * n + column;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        fx = vector<int>(m * n, -1);
        int ans = 0;
        if (grid[0][0] == '1')
        {
            ans += 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (grid[0][i] == '0')
            {
                continue;
            }
            else
            {
                ans += 1;
                if (grid[0][i - 1] == '1')
                {
                    if (join(getIndex(0,i), getIndex(0, i-1)))
                    {
                        ans -= 1;
                    }
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            if (grid[i][0] == '1')
            {
                ans += 1;
                if (grid[i - 1][0] == '1')
                {
                    if (join(getIndex(i, 0), getIndex(i - 1, 0)))
                    {
                        ans -= 1;
                    }
                }
            }
            for (int j = 1; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans += 1;
                    if (grid[i - 1][j] == '1')
                    {
                        if (join(getIndex(i, j), getIndex(i - 1, j)))
                        {
                            ans -= 1;
                        }
                    }
                    if (grid[i][j - 1] == '1')
                    {
                        if (join(getIndex(i, j), getIndex(i, j - 1)))
                        {
                            ans -= 1;
                        }
                    }
                }
                
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
        {'0','0','0','0','0'}
    };
    Solution s;
    cout << s.numIslands(grid) << endl;
}