#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> fx;

    int find(int x)
    {
        int p = x;
        while (fx[p] != p)
        {
            p = fx[p];
        }
        fx[x] = p;
        return p;
    }

    void join(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px != py)
        {
            fx[py] = px;
            fx[y] = px;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        fx = vector<int>();
        for (int i = 0; i < n; i++)
        {
            fx.emplace_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    join(i, j);
                }
            }
        }
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (fx[i] == i)
            {
                num += 1;
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> is = { {1,1,0} ,{1,1,0},{0,0,1} };
    cout << s.findCircleNum(is) << endl;
}