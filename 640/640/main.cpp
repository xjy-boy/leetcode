#include<iostream>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int ratio = 0;
        int num = 0;
        int index = 0;
        int now = 0;
        bool isLeft = true;
        bool isPositive = true;
        while (index < equation.size())
        {
            now = 0;
            if (equation[index] == 'x')
            {
                index += 1;
                if (!(isLeft^isPositive))
                {
                    ratio += 1;
                }
                else
                {
                    ratio -= 1;
                }
            }
            else if(equation[index] == '+')
            {
                index += 1;
                isPositive = true;
            }
            else if (equation[index] == '-')
            {
                index += 1;
                isPositive = false;
            }
            //等式左右切换
            else if (equation[index] == '=')
            {
                index += 1;
                isLeft = false;
                isPositive = true;
            }
            else
            {
                //解析数字
                now = 0;
                while (index < equation.size() && equation[index] >= '0' &&
                    equation[index] <= '9')
                {
                    now = now * 10 + equation[index] - '0';
                    index += 1;
                }

                //若后面是x
                if (index < equation.size() && equation[index] == 'x')
                {
                    index += 1;
                    if (!(isLeft ^ isPositive))
                    {
                        ratio += now;
                    }
                    else
                    {
                        ratio -= now;
                    }
                }
                //后面不是x
                else
                {
                    if (!(isLeft ^ isPositive))
                    {
                        num += now;
                    }
                    else
                    {
                        num -= now;
                    }
                }
            }
        }

        if (ratio == 0 && num != 0)
        {
            return "No solution";
        }
        else if (ratio == 0 && num == 0)
        {
            return "Infinite solutions";
        }
        else
        {
            return "x=" + to_string(-num / ratio);
        }
    }
};

int main()
{
    Solution s;
    string equation = "2x+3x-6x=x+2";
    cout << s.solveEquation(equation) << endl;
}