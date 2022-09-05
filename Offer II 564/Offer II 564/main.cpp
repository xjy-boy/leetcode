#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        unsigned long long preNum = 0;
        unsigned long long num[5] = { 0 };
        num[1] = 1;
        for (int i = 0; i < (n.size() + 1)  / 2; i++)
        {
            num[0] = num[0] * 10 + 9;
            num[1] *= 10;
            num[2] = num[2] * 10 + n[i] - '0';
        }
        preNum = num[2];
        num[3] = num[2] + 1;
        num[4] = num[2] - 1;
        unsigned long long templeNum = num[3];
        if (n.size() % 2 != 0)
        {
            templeNum = num[3] / 10;
        }
        while (templeNum > 0)
        {
            num[3] = num[3] * 10 + templeNum % 10;
            templeNum = templeNum / 10;
        }
        templeNum = num[4];
        if (n.size() % 2 != 0)
        {
            templeNum = num[4] / 10;
        }
        while (templeNum > 0)
        {
            num[4] = num[4] * 10 + templeNum % 10;
            templeNum = templeNum / 10;
        }
        for (int i = (n.size() + 1) / 2 ; i < n.size(); i++)
        {
            num[0] = num[0] * 10 + 9;
            num[1] *= 10;
            num[2] = num[2] * 10 + n[n.size() - i -1] - '0';
            preNum = preNum *10+ n[i] - '0';
        }
        num[0] /= 10;
        num[1] += 1;
        unsigned long long result = LONG_MAX;
        unsigned long long minDifference = LONG_MAX;
        for (int i = 0; i < 5; i++)
        {
            unsigned long templeDifference;
            if (num[i] > preNum)
            {
                templeDifference = num[i] - preNum;
            }
            else
            {
                templeDifference = preNum - num[i];
            }
            if (templeDifference == 0)
            {
                continue;
            }
            else if (templeDifference < minDifference)
            {
                minDifference = templeDifference;
                result = num[i];
            }
            else if (templeDifference == minDifference)
            {
                result = min(result, num[i]);
            }
        }

        return to_string(result);
    }
};

int main()
{
    Solution s;
    cout << s.nearestPalindromic("807045053224792883") << endl;
}