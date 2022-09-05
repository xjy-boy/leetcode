#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> preStack;
        stack<string> stringStack;
        int index = 0;
        string now = "";
        while (index < s.size())
        {
            if (s[index] == ']')
            {
                string next = "";
                for (int i = 0; i < preStack.top(); i++)
                {
                    next += now;
                }

                now = next;
                index += 1;
                now = stringStack.top() + now;

                preStack.pop();
                stringStack.pop();
            }
            else if(s[index] >= 'a' && s[index] <= 'z')
            {
                //½âÎö×Ö·û´®
                while (index < s.size() && s[index] >= 'a' && s[index] <= 'z')
                {
                    now += s[index];
                    index += 1;
                }
            }
            else
            {
                //½âÎöÊý×Ö
                int num = 0;
                while (index < s.size() && s[index] >= '0' && s[index] <= '9')
                {
                    num = num * 10 + s[index] - '0';
                    index += 1;
                }
                index += 1;
                preStack.push(num);
                stringStack.push(now);
                now = "";
            }
        }
        return now;
    }
};

int main()
{
    Solution solution;
    string s = "3[a2[c]]";
    cout << solution.decodeString(s) << endl;
}