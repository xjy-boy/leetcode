#include<iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int index = 0;
        return calculate(s, index);
    }

    int calculate(string s,int &index) {
        
        int symbol = 1;
        int ans = 0;
        while (index < s.size())
        {
            //ȥ���ո�
            while (index < s.size() && s[index] == ' ')
            {
                index += 1;
            }
            int num = 0;
            if (index < s.size() && s[index] == '(')
            {
                index += 1;
                num = calculate(s, index);
            }
            else
            {
                //ʶ������
                while (index < s.size() && s[index] >= '0' && s[index] <= '9')
                {
                    num = (s[index] - '0') + num * 10;
                    index += 1;
                }
            }
            ans += symbol * num;

            //ȥ���ո�
            while (index < s.size() && s[index] == ' ')
            {
                index += 1;
            }

            if (index >= s.size())
            {
                break;
            }
            else
            {
                //ʶ�����������������
                switch (s[index])
                {
                case '+':
                    index += 1;
                    symbol = 1;
                    break;
                case '-':
                    index += 1;
                    symbol = -1;
                    break;
                case ')':
                    index += 1;
                    return ans;
                default:
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
}