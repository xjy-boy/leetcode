#include<iostream>

using namespace std;


class Solution {
public:
    bool isNumber(string s) {
        int now = 0;
        /*
        * state = 0: 识别前导空阶段，检测到数字转2，'+','-'转1，'.'转3，' '保持其他报错。
        * state = 1: 识别整数符号阶段，检测数字转2，'.'转3,其他报错。
        * state = 2: 识别整数阶段，检测数字保持当前状态，检测到'.'转3且置flag为true，检测到e,E转4，检测到' '转7
        * state = 3: 识别小数阶段，检测数字保持当前状态，且置hasNum为true，检测到' '或'e'需要检测flag | hasNum，若为false报错。
        *              检测到' '转7，检测到'e'，'E'转4，其他报错
        * state = 4: 识别e后缀阶段,检测到'+','-'转5,数字转'6',其他报错
        * state = 5: 识别后缀整数符号阶段,检测到数字转5，其他报错
        * state = 6: 识别后缀整数阶段，检测到数字保持当前状态，' '转7。其他报错
        * state = 7: 识别后缀空阶段，检测到' '保持，其他报错。
        */
        int state = 0;
        bool flag = false;
        bool hasNum = false;

        for (int i = 0; i < s.size(); i++)
        {
            switch (state)
            {
            case 0:
                if (s[i] <= '9' && s[i] >= '0')
                {
                    state = 2;
                }
                else if (s[i] == '+' || s[i] == '-')
                {
                    state = 1;
                }
                else if (s[i] == '.')
                {
                    state = 3;
                }
                else if (s[i] != ' ')
                {
                    return false;
                }

                break;
            case 1:
                if (s[i] <= '9' && s[i] >= '0')
                {
                    state = 2;
                }
                else if (s[i] == '.')
                {
                    state = 3;
                }
                else
                {
                    return false;
                }
                break;
            case 2:
                if (s[i] == '.')
                {
                    flag = true;
                    state = 3;
                }
                else if (s[i] == ' ')
                {
                    state = 7;
                }
                else if (s[i] == 'E' || s[i] == 'e')
                {
                    state = 4;
                }
                else if(s[i] > '9' || s[i] < '0')
                {
                    return false;
                }
                break;
            case 3:
                if (s[i] <= '9' && s[i] >= '0')
                {
                    hasNum = true;
                }
                else if (s[i] == 'e' || s[i] == 'E')
                {
                    if (flag || hasNum)
                    {
                        state = 4;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (s[i] == ' ')
                {
                    if (flag || hasNum)
                    {
                        state = 7;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                break;
            case 4:
                if (s[i] == '+' || s[i] == '-')
                {
                    state = 5;
                }
                else if (s[i] <= '9' && s[i] >= '0')
                {
                    state = 6;
                }
                else
                {
                    return false;
                }
                break;
            case 5:
                if (s[i] <= '9' && s[i] >= '0')
                {
                    state = 6;
                }
                else
                {
                    return false;
                }
                break;
            case 6:
                if (s[i] == ' ')
                {
                    state = 7;
                }
                else if (s[i] > '9' || s[i] < '0')
                {
                    return false;
                }
                break;
            case 7:
                if (s[i] != ' ')
                {
                    return false;
                }
                break;
            default:
                break;
            }
        }

        if (state == 7 || state == 6 || state == 2)
        {
            return true;
        }
        else if (state == 3)
        {
            return flag || hasNum;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution solution;
    string s = "+.8";
    cout << solution.isNumber(s) << endl;
}