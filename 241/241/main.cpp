#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<int> symbol;
        vector<vector<vector<int>>> dp(nums.size());
        int index = 0;
        while (index < expression.size())
        {
            int num = 0;
            while (index < expression.size() && expression[index] >= '0' && expression[index] <= '9')
            {
                num = expression[index] - '0' + num * 10;
                index += 1;
            }
            nums.emplace_back(num);
            if (index < expression.size())
            {
                switch (expression[index])
                {
                case '+':
                    symbol.emplace_back(1);
                    break;
                case '-':
                    symbol.emplace_back(-1);
                    break;
                case '*':
                    symbol.emplace_back(0);
                    break;
                default:
                    break;
                }
            }
            index += 1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            dp.emplace_back(nums.size());
        }
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][i].emplace_back(nums[i]);
        }

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size() - i; j++)
            {
                int row = j;
                int column = j + i;
                for (int k = 0; k < i; k++)
                {
                    int row1 = row;
                    int column1 = row + k;
                    int row2 = row + 1 + k;
                    int column2 = column;
                    for (int num1 : dp[row][row + k])
                    {
                        for (int num2 : dp[row + 1 + k][column])
                        {
                            if (symbol[column1] == 0)
                            {
                                dp[row][column].emplace_back(num1 * num2);
                            }
                            else
                            {
                                dp[row][column].emplace_back(num1 + symbol[column1] * num2);
                            }
                        }
                    }
                }
            }
        }
        return dp[0].back();
    }
};

int main()
{
    Solution s;
    s.diffWaysToCompute("2-1-4-3-5");
}