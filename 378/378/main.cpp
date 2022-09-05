#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
private:
    int getNum(vector<vector<int>>& matrix, int num)
    {
        int n = matrix.size();
        int row = n - 1;
        int column = 0;
        int ans = 0;
        while (row >= 0 && column < n)
        {
            if (matrix[row][column] <= num)
            {
                ans += row + 1;
                column += 1;
            }
            else
            {
                row -= 1;
            }
        }
        return ans;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int num = getNum(matrix, mid);
            if (num < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        {1,5,9},
        {10,11,13},
        {12,13,15}
    };
    for (int i = 1; i <= 9; i++)
    {
        cout << s.kthSmallest(matrix,i) << endl;
    }
}