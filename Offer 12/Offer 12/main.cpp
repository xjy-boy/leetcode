#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    vector<vector<bool>> visited;
    string path;
    int m = 0;
    int n = 0;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        if (word.size() > m * n)
        {
            return false;
        }
        path = word;
        for (int i = 0; i < m; i++)
        {
            visited.emplace_back(vector<bool>(n, false));
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (find(board,i, j, 1))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool find(vector<vector<char>>& board, int i, int j, int index) 
    {
        if (index >= path.size())
        {
            return true;
        }
        visited[i][j] = true;

        if (j > 0 && board[i][j - 1] == path[index] && !visited[i][j-1])
        {
            if (find(board, i, j - 1, index + 1))
            {
                return true;
            }
        }

        if (j < n - 1 && board[i][j + 1] == path[index] && !visited[i][j + 1])
        {
            if (find(board, i, j + 1, index + 1))
            {
                return true;
            }
        }

        if (i > 0 && board[i - 1][j] == path[index] && !visited[i - 1][j])
        {
            if (find(board, i - 1, j, index + 1))
            {
                return true;
            }
        }

        if (i < m-1 && board[i + 1][j] == path[index] && !visited[i + 1][j])
        {
            if (find(board, i + 1, j, index + 1))
            {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    Solution s;
    cout << s.exist(board, "ABCCDE") << endl;
}