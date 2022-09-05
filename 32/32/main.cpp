#include<iostream>
#include<stack>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        return longestValidParentheses(s, 0);
    }

    int longestValidParentheses(string s,int index) {
        if (index >= s.size() - 1)
        {
            return 0;
        }
        stack<int> indexStack;
        for (int i = index; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                indexStack.push(i);
            }
            else
            {
                if (indexStack.empty())
                {
                    int ans = i - index;
                    if (ans > s.size() - i)
                    {
                        return ans;
                    }
                    else
                    {
                        return max(ans, longestValidParentheses(s, i + 1));
                    }
                }
                else
                {
                    indexStack.pop();
                }
            }
        }
        int ans = 0;
        int pre = s.size();
        while (!indexStack.empty())
        {
            ans = max(ans, pre - indexStack.top() - 1);
            pre = indexStack.top();
            indexStack.pop();
        }
        ans = max(ans, pre - index);
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.longestValidParentheses(")()())") << endl;
}