#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> preStack;
        int index = 0;
        int symbol = 1;
        int ans = 0;
        int pre = 0;
        bool flag = false;
        bool mult = false;
        while (index < s.size())
        {
            //去除空格
            while (index < s.size() && s[index] == ' ')
            {
                index += 1;
            }

            //识别数字
            int num = 0;
            while (index < s.size() && s[index] >= '0' && s[index] <= '9')
            {
                num = s[index] - '0' + num * 10;
                index += 1;
            }
            if (flag)
            {
                if (mult)
                {
                    pre = pre * num;
                }
                else
                {
                    pre = pre / num;
                }
            }
            else
            {
                pre = num * symbol;
            }

            //去除空格
            while (index < s.size() && s[index] == ' ')
            {
                index += 1;
            }
            //识别运算符
            if (index >= s.size())
            {
                ans += pre;
            }
            else
            {
                switch (s[index])
                {
                case '+':
                    ans += pre;
                    symbol = 1;
                    flag = false;
                    break;
                case '-':
                    ans += pre;
                    symbol = -1;
                    flag = false;
                    break;
                case '*':
                    flag = true;
                    mult = true;
                    break;
                case '/':
                    flag = true;
                    mult = false;
                    break;
                }
                index += 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.calculate("3+5/2 * 2 + 1") << endl;
}