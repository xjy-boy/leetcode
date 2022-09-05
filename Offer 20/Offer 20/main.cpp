#include<iostream>

using namespace std;


class Solution {
public:
    bool isNumber(string s) {
        int now = 0;
        /*
        * state = 0: ʶ��ǰ���ս׶Σ���⵽����ת2��'+','-'ת1��'.'ת3��' '������������
        * state = 1: ʶ���������Ž׶Σ��������ת2��'.'ת3,��������
        * state = 2: ʶ�������׶Σ�������ֱ��ֵ�ǰ״̬����⵽'.'ת3����flagΪtrue����⵽e,Eת4����⵽' 'ת7
        * state = 3: ʶ��С���׶Σ�������ֱ��ֵ�ǰ״̬������hasNumΪtrue����⵽' '��'e'��Ҫ���flag | hasNum����Ϊfalse����
        *              ��⵽' 'ת7����⵽'e'��'E'ת4����������
        * state = 4: ʶ��e��׺�׶�,��⵽'+','-'ת5,����ת'6',��������
        * state = 5: ʶ���׺�������Ž׶�,��⵽����ת5����������
        * state = 6: ʶ���׺�����׶Σ���⵽���ֱ��ֵ�ǰ״̬��' 'ת7����������
        * state = 7: ʶ���׺�ս׶Σ���⵽' '���֣���������
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