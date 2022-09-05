#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        int n = 0; //·Ö×Ó
        int d = 1;  //·ÖÄ¸

        int nextN = 0;
        int nextD = 0;
        int symbol = 1;
        int index = 0;
        int t = 0;
        while (index < expression.size())
        {
            if (expression[index] == '+')
            {
                index += 1;
                symbol = 1;
            }
            else if (expression[index] == '-')
            {
                index += 1;
                symbol = -1;
            }
            else
            {
                symbol = 1;
            }
            nextN = 0;
            while (expression[index] != '/')
            {
                nextN = nextN * 10 + expression[index] - '0';
                index += 1;
            }
            index += 1;
            nextD = 0;
            while (index < expression.size() && expression[index]>='0'
                && expression[index] <= '9')
            {
                nextD = nextD * 10 + expression[index] - '0';
                index += 1;
            }
            t = getLowestMul(d, nextD);
            n = t / d * n;
            nextN = t / nextD * nextN * symbol;
            d = t;
            n = n + nextN;
            if (n == 0)
            {
                d = 1;
            }
            else
            {
                t = getGreatestDiv(abs(n), d);
                n = n / t;
                d = d / t;
            }
        }
        return to_string(n) + "/" + to_string(d);
    }
    
    inline int getGreatestDiv(int num1, int num2)
    {
        int maxNum = max(num1, num2);
        int minNum = min(num1, num2);
        int t = 0;
        while (maxNum % minNum != 0)
        {
            t = maxNum % minNum;
            maxNum = minNum;
            minNum = t;
        }
        return minNum;
    }

    inline int getLowestMul(int num1, int num2)
    {
        return num1 / getGreatestDiv(num1, num2) * num2;
    }
};

int main()
{
    Solution s;
    string expression = "1/3-1/2";
    cout << s.fractionAddition(expression) << endl;
}
