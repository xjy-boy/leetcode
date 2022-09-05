#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c)
        {
            return mat;
        }
        vector<vector<int>> ans = vector<vector<int>>();
        int index = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (index == 0)
                {
                    ans.emplace_back(c, 0);
                }
                ans.back()[index] = mat[i][j];
                index = (index + 1) % c;
            }
        }
        return ans;
   }
};