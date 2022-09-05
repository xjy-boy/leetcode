#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> ans = vector<int>(prices.size(), 0);
        stack<int> smallStack;
        int result = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            while (!smallStack.empty() && prices[i] > prices[smallStack.top()])
            {
                ans[i] = max(ans[smallStack.top()] + prices[i] - prices[smallStack.top()],ans[i]);
                result = max(result, ans[i]);
                smallStack.pop();
            }
            smallStack.push(i);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,1,4,5,2,9,7 };
    cout << s.maxProfit(nums) << endl;
}