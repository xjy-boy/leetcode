#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> result;
        for (int i = 0; i < grid[0].size(); i++)
        {
            int nowColumn = i;
            int nowRow = 0;
            while (nowRow < grid.size())
            {
                //ÓÒÉÏ½Çµ½×óÏÂ½ÇµÄµ²°å£¬¼ì²â×ó²àµ²°å
                if (grid[nowRow][nowColumn] < 0)
                {
                    if (nowColumn > 0 && grid[nowRow][nowColumn-1] < 0)
                    {
                        nowColumn -= 1;
                        nowRow += 1;
                    }
                    else
                    {
                        nowColumn = -1;
                        break;
                    }
                }
                //ÓÒÉÏ½Çµ½×óÏÂ½ÇµÄµ²°å£¬¼ì²âÓÒ²àµ²°å
                else
                {
                    if (nowColumn < grid[0].size()-1 && grid[nowRow][nowColumn+1] > 0)
                    {
                        nowColumn += 1;
                        nowRow += 1;
                    }
                    else
                    {
                        nowColumn = -1;
                        break;
                    }
                }
            }
            result.push_back(nowColumn);
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    //vector<vector<int>> grid = { {1,1,1,-1,-1} ,{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1} };
    vector<vector<int>> grid = { {1,1,1,1,1,1} ,{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1} };
    vector<int> result = solution.findBall(grid);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}