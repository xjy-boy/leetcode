#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int dir[4][2] =
    {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
    int border[4] = { 0,0,0,0 }; // {minR,maxR,minC,maxC}
    int change[4][4] =
    {
        {0,1},
        {3,-1},
        {1,-1},
        {2,1},
    };
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> matrix;
        for (int i = 0; i < m; i++)
        {
            matrix.emplace_back(n, 0);
        }
        border[1] = m - 1;
        border[3] = n - 1;
        int state = 0;
        int row = 0;
        int column = 0;

        for (int i = 0; i < m * n; i++)
        {
            if (head)
            {
                matrix[row][column] = head->val;
                head = head->next;
            }
            else
            {
                matrix[row][column] = -1;
            }
            int nextRow = row + dir[state][0];
            int nextColumn = column + dir[state][1];
            if (nextRow > border[1] || nextRow < border[0]
                || nextColumn > border[3] || nextColumn < border[2])
            {
                border[change[state][0]] += change[state][1];
                state = (state + 1) % 4;
                row += dir[state][0];
                column += dir[state][1];
            }
            else
            {
                row = nextRow;
                column = nextColumn;
            }
        }
        return matrix;
    }
};