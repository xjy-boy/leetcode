#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int ans = 0;
        int rows = heightMap.size();
        int columns = heightMap[0].size();
        if (rows < 2 || columns < 2)
        {
            return 0;
        }

        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int, int>>> searchQueue;
        vector<vector<bool>> visit = vector<vector<bool>>(rows,
            vector<bool>(columns,false));
        visit[0][0] = true;
        visit[0][columns - 1] = true;
        visit[rows - 1][0] = true;
        visit[rows - 1][columns - 1] = true;

        for (int i = 1; i < columns - 1; i++)
        {
            visit[0][i] = true;
            visit[rows - 1][i] = true;
            searchQueue.push(pair<int, int>(
                heightMap[0][i],i
                ));
            searchQueue.push(pair<int, int>(
                heightMap[rows - 1][i], i + (rows - 1) * columns
                ));
        }

        for (int i = 1; i < rows - 1; i++)
        {
            visit[i][0] = true;
            visit[i][columns - 1] = true;
            searchQueue.push(pair<int, int>(
                heightMap[i][0], i * columns
                ));
            searchQueue.push(pair<int, int>(
                heightMap[i][columns - 1], i * columns + columns - 1
                ));
        }

        int row = 0;
        int column = 0;
        int nextRow = 0;
        int nextColumn;
        vector<vector<int>> dir = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1},
        };
        pair<int, int> next;
        while (!searchQueue.empty())
        {
            next = searchQueue.top();
            searchQueue.pop();
            row = next.second / columns;
            column = next.second % columns;
            for (int i = 0; i < 4; i++)
            {
                nextRow = row + dir[i][0];
                nextColumn = column + dir[i][1];
                if (nextRow >= 0 && nextRow < rows
                    && nextColumn >= 0 && nextColumn < columns
                    && ! visit[nextRow][nextColumn])
                {
                    visit[nextRow][nextColumn] = true;
                    if (heightMap[nextRow][nextColumn] < heightMap[row][column])
                    {
                        ans += heightMap[row][column] - heightMap[nextRow][nextColumn];
                        heightMap[nextRow][nextColumn] = heightMap[row][column];
                    }
                    searchQueue.push(pair<int, int>(
                        heightMap[nextRow][nextColumn],
                        nextRow * columns + nextColumn
                        ));
                }

            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> m = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    cout << s.trapRainWater(m) << endl;
}