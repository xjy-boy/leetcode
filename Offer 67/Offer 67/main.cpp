#include<iostream>

using namespace std;


class Solution {
public:
    int strToInt(string str) {
        int index = 0;
        while (index < str.size() && str[index] == ' ')
        {
            index += 1;
        }
        if (index == str.size())
        {
            return 0;
        }
        else if (str[index] == '+')
        {
            return strToPositive(str, index + 1);
        }
        else if (str[index] == '-')
        {
            return strToNegative(str, index + 1);
        }
        else if (str[index] >= '0' && str[index] <= '9')
        {
            return strToPositive(str, index);
        }
        else
        {
            return 0;
        }
    }

    int strToPositive(string &str,int start)
    {
        int ans = 0;
        int index = start;
        while (index < str.size() && str[index] >= '0' && str[index] <= '9')
        {
            int now = str[index] - '0';
            if ((INT_MAX - now) / 10 < ans)
            {
                return INT_MAX;
            }
            else
            {
                ans = ans * 10 + now;
            }
            index += 1;
        }
        return ans;
    }

    int strToNegative(string& str, int start)
    {
        int ans = 0;
        int index = start;
        while (index < str.size() && str[index] >= '0' && str[index] <= '9')
        {
            int now = str[index] - '0';
            if ((INT_MIN + now) / 10 > ans)
            {
                return INT_MIN;
            }
            else
            {
                ans = ans * 10 - now;
            }
            index += 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.strToInt("4193 with words") << endl;
}