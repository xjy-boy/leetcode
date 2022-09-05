#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        
        int pushInex = 0;
        int popIndex = 0;
        stack<int> dataStack;
        while (popIndex < popped.size())
        {
            if (dataStack.empty() || dataStack.top() != popped[popIndex])
            {
                if (pushInex >= pushed.size())
                {
                    return false;
                }
                dataStack.push(pushed[pushInex]);
                pushInex += 1;
            }
            else
            {
                dataStack.pop();
                popIndex += 1;
            }
        }
        return dataStack.empty();
    }
};

int main()
{
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> poped = { 4,5,3,2,1 };
    Solution s;
    cout << s.validateStackSequences(pushed, poped) << endl;
}