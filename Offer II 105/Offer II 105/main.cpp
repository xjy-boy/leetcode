#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> fx;
    int ans;
    int find(int x) {
        int p = x;
        while (fx[p] >= 0) {
            p = fx[p];
        }
        if (fx[x] >= 0) {
            fx[x] = p;
        }
        return p;
    }

    void join(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);
        fx[xParent] += fx[yParent];
        fx[yParent] = xParent;
        ans = min(ans, fx[xParent]);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        fx = vector<int>(m * n, -1);
        ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }
                ans = min(ans, -1);
                if (i > 0 && grid[i - 1][j] == 1 && j > 0 && grid[i][j - 1] == 1) {
                    if (find((i - 1) * n + j) != find(i * n + j - 1)) {
                        join(i * n + j - 1, (i - 1) * n + j);
                        join(i * n + j - 1, i * n + j);
                    }
                    else {
                        join(i * n + j - 1, i * n + j);
                    }
                }
                else if (i > 0 && grid[i - 1][j] == 1)
                {
                    join((i - 1) * n + j, i * n + j);
                }  
                else if (j > 0 && grid[i][j - 1] == 1)
                {
                    join(i * n + j - 1, i * n + j);
                }
            }
        }
        return -ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1,1,0},
        {1,1,1}
    };
    cout << solution.maxAreaOfIsland(grid) << endl;
}