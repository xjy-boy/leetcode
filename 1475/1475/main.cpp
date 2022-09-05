#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = vector<int>(prices.size(), 0);
        stack<int> searchStack;
        for (int i = 0; i < prices.size(); i++)
        {
            while (!searchStack.empty()
                && prices[searchStack.top()] >= prices[i])
            {
                ans[searchStack.top()] = prices[searchStack.top()] - prices[i];
                searchStack.pop();
            }
            searchStack.push(i);
        }
        while (!searchStack.empty())
        {
            ans[searchStack.top()] = prices[searchStack.top()];
            searchStack.pop();
        }
        return ans;
    }
};