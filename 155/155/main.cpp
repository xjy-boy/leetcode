#include<iostream>
#include<stack>

using namespace std;


class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;
public:
    MinStack() {

    }

    void push(int val) {
        dataStack.push(val);
        if (minStack.empty() || minStack.top() > val)
        {
            minStack.push(val);
        }
        else
        {
            minStack.push(minStack.top());
        }
    }

    void pop() {
        dataStack.pop();
        minStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
