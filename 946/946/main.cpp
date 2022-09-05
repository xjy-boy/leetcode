#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int index1 = 0;
        int index2 = 0;
        stack<int> searchStack;
        while (index2 < popped.size())
        {
            while ( index1 < pushed.size() && 
                (searchStack.empty()
                || searchStack.top() != popped[index2]))
            {
                searchStack.push(pushed[index1]);
                index1 += 1;
            }
            if (!searchStack.empty() &&
                searchStack.top() == popped[index2])
            {
                searchStack.pop();
                index2 += 1;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};