#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> dpRow = vector<int>(m, 0);
        vector<int> dpColumn = vector<int>(n, 0);
        int ans = 0;
        for (vector<int> indice : indices)
        {
            dpRow[indice[0]] += 1;
            dpColumn[indice[1]] += 1;
        }
        int odd = 0;
        int even = 0;
        for (int num : dpRow)
        {
            if (num % 2 != 0)
            {
                odd += 1;
            }
            else
            {
                even += 1;
            }
        }

        for (int num : dpColumn)
        {
            if (num % 2 == 0)
            {
                ans += odd;
            }
            else
            {
                ans += even;
            }
        }
        return ans;
    }
};