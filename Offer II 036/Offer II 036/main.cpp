#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tokenStack;
        for (string s : tokens)
        {
            if (s == "+")
            {
                int n1 = tokenStack.top();
                tokenStack.pop();
                int n2 = tokenStack.top();
                tokenStack.pop();

                tokenStack.push(n1 + n2);
            }
            else if (s == "-")
            {
                int n1 = tokenStack.top();
                tokenStack.pop();
                int n2 = tokenStack.top();
                tokenStack.pop();

                tokenStack.push(n2 - n1);
            }
            else if (s == "*")
            {
                int n1 = tokenStack.top();
                tokenStack.pop();
                int n2 = tokenStack.top();
                tokenStack.pop();

                tokenStack.push(n1 * n2);
            }
            else if (s == "/")
            {
                int n1 = tokenStack.top();
                tokenStack.pop();
                int n2 = tokenStack.top();
                tokenStack.pop();

                tokenStack.push(n2 / n1);
            }
            else
            {
                tokenStack.push(atoi(s.c_str()));
            }
        }
        return tokenStack.top();
    }
};

int main()
{
    Solution solution = Solution();
    vector<string> tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    cout << solution.evalRPN(tokens) << endl;
}