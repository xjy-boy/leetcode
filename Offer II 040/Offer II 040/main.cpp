#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        if (matrix.empty())
        {
            return 0;
        }
        vector<int> heights = vector<int>(matrix[0].size());
        int result = 0;
        for (string s : matrix)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                {
                    heights[i] += 1;
                }
                else
                {
                    heights[i] = 0;
                }
            }
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }

    int largestRectangleArea(vector<int>heights) {
        stack<int> biggerStack;
        int result = 0;
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        biggerStack.push(0);
        for (int i = 1; i < heights.size(); i++)
        {
            if (heights[i] >= heights[biggerStack.top()])
            {
                biggerStack.push(i);
            }
            else
            {
                while (!biggerStack.empty() && heights[i] < heights[biggerStack.top()])
                {
                    int temple = heights[biggerStack.top()];
                    biggerStack.pop();
                    temple *= i - biggerStack.top() - 1;
                    if (temple > result)
                    {
                        result = temple;
                    }
                }
                biggerStack.push(i);
            }
        }
        return result;
    }
};

int main()
{
    vector<string> matrix = { "00"};
    Solution solution = Solution();
    cout << solution.maximalRectangle(matrix) << endl;
}