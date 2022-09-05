#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bStack;
        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                bStack.push(c);
                break;
            case ')':
                if (bStack.empty() || bStack.top() != '(')
                {
                    return false;
                }
                bStack.pop();
                break;
            case ']':
                if (bStack.empty() || bStack.top() != '[')
                {
                    return false;
                }
                bStack.pop();
                break;
            case '}':
                if (bStack.empty() || bStack.top() != '{')
                {
                    return false;
                }
                bStack.pop();
                break;
            }
        }
        return bStack.empty();
    }
};