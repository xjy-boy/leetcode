#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int rows = 0;
    int columns = 0;
    vector<pair<int, int>> dir = {
        pair<int,int>(-1,0),
        pair<int,int>(0,-1),
        pair<int,int>(1,0),
        pair<int,int>(0,1),
    };
    /*
    void display(vector<vector<int>>& isInfected)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << i << ":\t";
            for (int j = 0; j < columns; j++)
            {
                int num = isInfected[i][j];
                if (num == 0)
                {
                    cout << "-";
                }
                else if (num == -1)
                {
                    cout << "U";
                }
                else
                {
                    cout << "O";
                }
            }
            cout << endl;
        }
        cout << endl;
    }*/

    int containVirus(vector<vector<int>>& isInfected) {
        rows = isInfected.size();
        columns = isInfected[0].size();
        //display(isInfected);
        return virus(isInfected);
    }

    int virus(vector<vector<int>>& isInfected) {
        int ans = 0;
        int result = 0;

        int index = 1;
        int nextIndex = 0;
        int next = 0;
     
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (isInfected[i][j] == 1)
                {
                    index += 1;
                    result = dfs(isInfected, i, j, index);
                    if (result > next)
                    {
                        nextIndex = index;
                        next = result;
                    }
                }
            }
        }
        
        if (next == 0)
        {
            return 0;
        }
        else
        {
            int nextRow = 0;
            int nextColumn = 0;

            //计算防火墙个数,并将周围置0
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    //当前选中的区域
                    if (isInfected[i][j] == nextIndex)
                    {
                        //计算防火墙个数,并将周围置0
                        for (pair<int, int>& d : dir)
                        {
                            nextRow = i + d.first;
                            nextColumn = j + d.second;

                            if (nextRow >= 0 && nextRow < rows &&
                                nextColumn >= 0 && nextColumn < columns)
                            {
                                if (isInfected[nextRow][nextColumn] <= 0 &&
                                    isInfected[nextRow][nextColumn] != -1)
                                {
                                    ans += 1;
                                    isInfected[nextRow][nextColumn] = 0;
                                }
                            }
                        }
                    }
                }
            }

            //将当前选中的区域置为-1
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    //当前选中的区域
                    if (isInfected[i][j] == nextIndex || isInfected[i][j] == -1)
                    {
                        //将当前选中的区域置为-1
                        isInfected[i][j] = -1;
                    }
                }
            }

            //将未选中的区域以及周围重置为1
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    //当前未选中的区域
                    if (isInfected[i][j] > 1)
                    {
                        isInfected[i][j] = 1;
                        for (pair<int, int>& d : dir)
                        {
                            nextRow = i + d.first;
                            nextColumn = j + d.second;

                            if (nextRow >= 0 && nextRow < rows &&
                                nextColumn >= 0 && nextColumn < columns
                                && isInfected[nextRow][nextColumn] <= 0
                                && isInfected[nextRow][nextColumn] != -1)
                            {
                                isInfected[nextRow][nextColumn] = 1;
                            }
                        }
                    }
                }
            }
            //display(isInfected);
            return ans + virus(isInfected);
        }
    }

    //将当前区域设为index，将当前区域下次要感染的区域设为-index
    int dfs(vector<vector<int>>& isInfected, int row, int column, int index)
    {
        int ans = 0;
        int nextRow = 0;
        int nextColumn = 0;
        isInfected[row][column] = index;
        for (pair<int, int>& d : dir)
        {
            nextRow = row + d.first;
            nextColumn = column + d.second;

            if (nextRow >= 0 && nextRow < rows &&
                nextColumn >= 0 && nextColumn < columns)
            {
                if (isInfected[nextRow][nextColumn] <= 0 
                    && isInfected[nextRow][nextColumn] != -index
                    && isInfected[nextRow][nextColumn] != -1)
                {
                    ans += 1;
                    isInfected[nextRow][nextColumn] = -index;
                }
                else if (isInfected[nextRow][nextColumn] == 1)
                {
                    ans += dfs(isInfected, nextRow, nextColumn, index);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> nums = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
        {0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    cout << s.containVirus(nums) << endl;
}