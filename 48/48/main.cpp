#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() / 2; i++)
        {

            for (int j = 0; j < matrix.size() - 2*i - 1; j++)
            {
                int r1 = i;
                int c1 = i + j;

                int r2 = i + j;
                int c2 = matrix.size() - i - 1;

                int r3 = matrix.size() - i - 1;
                int c3 = matrix.size() - i - 1 - j;

                int r4 = matrix.size() - i - 1 - j;
                int c4 = i;

                int t = matrix[r2][c2];
                matrix[r2][c2] = matrix[r1][c1];
                matrix[r1][c1] = matrix[r4][c4];
                matrix[r4][c4] = matrix[r3][c3];
                matrix[r3][c3] = t;
            }
        }
    }
};