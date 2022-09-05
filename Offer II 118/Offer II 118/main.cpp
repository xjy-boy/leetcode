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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        fx = vector<int>();
        for (int i = 0; i < n + 1; i++)
        {
            fx.emplace_back(i);
        }
        for (vector<int> edge : edges)
        {
            if (find(edge[0]) == find(edge[1]))
            {
                return edge;
            }
            else
            {
                join(edge[0], edge[1]);
            }
        }
        return {};
    }
};

int main()
{
    vector<vector<int>> e = { {1, 4}, {3, 4}, {1, 3}, {1, 2}, {4, 5} };
    Solution s;
    s.findRedundantConnection(e);
}