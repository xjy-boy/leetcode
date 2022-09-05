#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        //¼ÆËãÇ°×ººÍ
        int n = grid.size();
        
        for (int i = 1; i < n; i++)
        {
            grid[i][0] += grid[i - 1][0];
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j] += grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
            }
        }


        return construct(grid, 0, grid.size() - 1, 0, grid.size() - 1);
    }

    Node* construct(vector<vector<int>>& grid,int left,int right,int top,int bottom) {
        Node* p = new Node();
        int sum = 0;
        if (top == 0 && left == 0)
        {
            sum = grid[bottom][right];
        }
        else if (top == 0)
        {
            sum = grid[bottom][right] - grid[bottom][left - 1];
        }
        else if (left == 0)
        {
            sum = grid[bottom][right] - grid[top - 1][right];
        }
        else
        {
            sum = grid[bottom][right] - grid[bottom][left - 1] - grid[top - 1][right]
                + grid[top - 1][left - 1];
        }
        
        if (sum == 0)
        {
            p->val = false;
            p->isLeaf = true;
        }
        else if (sum == pow(right - left + 1, 2))
        {
            p->val = true;
            p->isLeaf = true;
        }
        else
        {
            p->isLeaf = false;
            int columnMid = (left + right) / 2;
            int rowMid = (top + bottom) / 2;
            p->topLeft = construct(grid, left, columnMid, top, rowMid);
            p->topRight = construct(grid, columnMid + 1, right, top, rowMid);
            p->bottomLeft = construct(grid, left, columnMid, rowMid + 1, bottom);
            p->bottomRight = construct(grid, columnMid + 1, right, rowMid + 1, bottom);
        }
        return p;
    }
};

int main()
{
    vector<vector<int>> grid
        {{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};
    Solution s;
    Node *p = s.construct(grid);
    return 0;
}