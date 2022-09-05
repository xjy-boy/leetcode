#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    string temple;
    vector<string> result;
    int nowSum = 0;
    int leftNum = 0;
public:
    vector<string> generateParenthesis(int n) {
        temple = "";
        result.clear();
        backtrack(n);
        return result;
    }
    void backtrack(int n)
    {
        if (temple.length() == n << 1)
        {
            result.emplace_back(temple);
        }
        else
        {
            if (leftNum < n)
            {
                temple.push_back('(');
                nowSum += 1;
                leftNum += 1;
                backtrack(n);
                temple.pop_back();
                nowSum -= 1;
                leftNum -= 1;
            }

            if (nowSum > 0)
            {
                temple.push_back(')');
                nowSum -= 1;
                backtrack(n);
                temple.pop_back();
                nowSum += 1;
            }
        }
    }
};

int main()
{
    Solution s;
    s.generateParenthesis(5);
}