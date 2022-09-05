#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class NestedInteger {
private:
    int value;
    vector<NestedInteger> list;
public:
         // Constructor initializes an empty nested list.
        NestedInteger()
        {
            value = 0;
        }
    
             // Constructor initializes a single integer.
        NestedInteger(int _value)
        {
            value = _value;
        }
    
             // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const
        {
            return true;
        }
    
             // Return the single integer that this NestedInteger holds, if it holds a single integer
             // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const
        {
            return value;
        }
    
             // Set this NestedInteger to hold a single integer.
        void setInteger(int value)
        {
            this->value = value;
        }
    
             // Set this NestedInteger to hold a nested list and adds a nested integer to it.
        void add(const NestedInteger& ni)
        {
            list.push_back(ni);
        }
             // Return the nested list that this NestedInteger holds, if it holds a nested list
             // The result is undefined if this NestedInteger holds a single integer
        const vector<NestedInteger>& getList() const
        {
            return list;
        }
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        int index = 0;
        NestedInteger ans;
        stack<NestedInteger> searchStack;
        searchStack.push(ans);
        while (index < s.size())
        {
            if (s[index] == '[')
            {
                index += 1;
                searchStack.push(NestedInteger());
            }
            else if (s[index] == ',')
            {
                index += 1;
            }
            else if (s[index] == ']')
            {
                NestedInteger n = searchStack.top();
                searchStack.pop();
                searchStack.top().add(n);
                index += 1;
            }
            else
            {
                //½âÎöint
                int num = 0;
                int symbol = 1;
                if (s[index] == '-')
                {
                    index += 1;
                    symbol = -1;
                }
                while (index < s.size() && s[index] >= '0' && s[index] <= '9')
                {
                    num = num * 10 + s[index] - '0';
                    index += 1;
                }
                NestedInteger n(num * symbol);
                searchStack.top().add(n);
            }
        }
        return searchStack.top().getList()[0];
    }
};

int main()
{
    Solution solution;
    string s = "[123,456,[788,799,833],[[]],10,[]]";
    solution.deserialize(s);
}