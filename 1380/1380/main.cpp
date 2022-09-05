#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> columnMax(n, 0); //每一列最大的元素位置
        vector<int> rowMin(m, 0); //每一行最小的元素位置

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < matrix[i][rowMin[i]]) {
                    rowMin[i] = j;
                }
                if (matrix[i][j] > matrix[columnMax[j]][j]) {
                    columnMax[j] = i;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (columnMax[rowMin[i]] == i) {
                result.push_back(matrix[i][rowMin[i]]);
            }
        }
        return result;
    }
};


int main() {
    vector<vector<int>> matrix = { {1,10,4,2},{9,3,8,7},{15,16,17,12} };
    Solution solution = Solution();
    cout << solution.luckyNumbers(matrix).size() << endl;

}