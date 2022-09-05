#include<iostream>
#include<stack>

using namespace std;


class CQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    CQueue() {

    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty())
        {
            return -1;
        }
        int ans = stack2.top();
        stack2.pop();
        return ans;
    }
};

int main()
{

}