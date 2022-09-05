#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
                    temple *= i - biggerStack.top()  - 1;
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
    vector<int> heights = { 2,1,5,6,2,3 };
    Solution solution = Solution();
    cout << solution.largestRectangleArea(heights) << endl;
}