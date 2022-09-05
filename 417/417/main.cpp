#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> atlantic = vector<vector<bool>>();
        vector<vector<bool>> pacific = vector<vector<bool>>();
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
            {
                pacific.push_back(vector<bool>(n, true));
            }
            else
            {
                pacific.push_back(vector<bool>(n, false));
            }
            if (i == m - 1)
            {
                atlantic.push_back(vector<bool>(n, true));
            }
            else
            {
                atlantic.push_back(vector<bool>(n, false));
            }
            atlantic.back()[n - 1] = true;
            pacific.back()[0] = true;
        }

        queue<pair<int, int>> searchQueue1;
        queue<pair<int, int>> searchQueue2;
        searchQueue1.push(pair<int, int>(0, 0));
        searchQueue2.push(pair<int, int>(m-1, n-1));
        for (int i = 1; i < n; i++)
        {
            searchQueue1.push(pair<int, int>(0, i));
            searchQueue2.push(pair<int, int>(m - 1, n - 1 - i));
        }
        for (int i = 1; i < m; i++)
        {
            searchQueue1.push(pair<int, int>(i, 0));
            searchQueue2.push(pair<int, int>(m - 1 - i, n - 1));
        }
        while (!searchQueue1.empty())
        {
            int row = searchQueue1.front().first;
            int column = searchQueue1.front().second;
            if (row != 0 && !pacific[row - 1][column] && heights[row][column] <= heights[row-1][column])
            {
                pacific[row - 1][column] = true;
                searchQueue1.push(pair<int, int>(row - 1, column));
            }

            if (row != m-1 && !pacific[row + 1][column] && heights[row][column] <= heights[row + 1][column])
            {
                pacific[row + 1][column] = true;
                searchQueue1.push(pair<int, int>(row + 1, column));
            }

            if (column != 0 && !pacific[row][column - 1] && heights[row][column] <= heights[row][column - 1])
            {
                pacific[row][column - 1] = true;
                searchQueue1.push(pair<int, int>(row, column - 1));
            }

            if (column != n-1 && !pacific[row][column + 1] && heights[row][column] <= heights[row][column + 1])
            {
                pacific[row][column + 1] = true;
                searchQueue1.push(pair<int, int>(row, column + 1));
            }

            searchQueue1.pop();
        }

        while (!searchQueue2.empty())
        {
            int row = searchQueue2.front().first;
            int column = searchQueue2.front().second;
            if (row != 0 && !atlantic[row - 1][column] && heights[row][column] <= heights[row - 1][column])
            {
                atlantic[row - 1][column] = true;
                searchQueue2.push(pair<int, int>(row - 1, column));
            }

            if (row != m - 1 && !atlantic[row + 1][column] && heights[row][column] <= heights[row + 1][column])
            {
                atlantic[row + 1][column] = true;
                searchQueue2.push(pair<int, int>(row + 1, column));
            }

            if (column != 0 && !atlantic[row][column - 1] && heights[row][column] <= heights[row][column - 1])
            {
                atlantic[row][column - 1] = true;
                searchQueue2.push(pair<int, int>(row, column - 1));
            }

            if (column != n-1 && !atlantic[row][column + 1] && heights[row][column] <= heights[row][column + 1])
            {
                atlantic[row][column + 1] = true;
                searchQueue2.push(pair<int, int>(row, column + 1));
            }

            searchQueue2.pop();
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m ; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({ i,j });
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    s.pacificAtlantic(heights);
}