#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        int a[8][2] = { {1,2}, {-1,2}, {1,-2}, {-1,-2}, 
                        {2,1}, {-2,1}, {2,-1}, {-2,-1}};
        vector<vector<vector<double>>> dp;
        dp.push_back(vector<vector<double>>());
        dp.push_back(vector<vector<double>>());
        for (int i = 0; i < n; i++) {
            dp[0].push_back(vector<double>(n, 1));
            dp[1].push_back(vector<double>(n, 1));
        }
        int pre = 1;
        int now = 0;

        for (int i = 0; i < k; i++) {
            now = 1 - now;
            pre = 1 - pre;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    //¼õÉÙ¼ÆËãÁ¿
                    if (j >= (n + 1) / 2 ) {
                        dp[now][j][k] = dp[now][n - j - 1][k];
                    }
                    else if (k < j) {
                        dp[now][j][k] = dp[now][k][j];
                    }
                    else if (k > (n - 1) /2 ) {
                        dp[now][j][k] = dp[now][j][n - k - 1];
                    }
                    else {
                        dp[now][j][k] = 0;
                        for (int m = 0; m < 8; m++) {
                            int tj = j + a[m][0];
                            int tk = k + a[m][1];
                            if (tj < 0 || tk < 0 || tj >= n || tk >= n) {
                                continue;
                            }
                            else {
                                dp[now][j][k] += dp[pre][tj][tk];
                            }
                        }
                        dp[now][j][k] /= 8;
                    }
                }
            }
        }
        return dp[now][row][column];
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.knightProbability(3, 2, 0, 0) << endl;
    cout << solution.knightProbability(1, 0, 0, 0) << endl;
    cout << solution.knightProbability(3, 0, 2, 0) << endl;
}