#include<iostream>

using namespace std;


class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3)
        {
            return false;
        }
        else if (num[0] == '0')
        {
            if (num[1] == '0')
            {
                return isAdditiveNumber(num.substr(2, num.length() - 2), "0", "0");
            }
            else
            {
                string pre1 = "0";
                string pre2 = "";
                for (int i = 1; i < num.size() / 2 + 1; i++)
                {
                    pre2 += num[i];
                    if (isAdditiveNumber(num.substr(i+1,num.length()-i-1), pre1, pre2))
                    {
                        return true;
                    }
                }
                return false;
            }
        }
        else
        {
            string pre1 = "";
            for (int i = 0; i < num.size() / 2; i++)
            {
                pre1 += num[i];
                if (num[i+1] == '0')
                {
                    if (isAdditiveNumber(num.substr(i + 2, num.length() - i - 2), pre1, "0"))
                    {
                        return true;
                    }
                }
                else
                {
                    string pre2;
                    for (int j = i + 1; j < (num.size() + i + 1) / 2; j++)
                    {
                        pre2 += num[j];
                        if (isAdditiveNumber(num.substr(j + 1, num.length() - j - 1), pre1, pre2))
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    }

    bool isAdditiveNumber(string num,string pre1,string pre2) {
        string next = sum(pre1, pre2);
        if (num.length() < next.length())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < next.length(); i++)
            {
                if (num[i] != next[i])
                {
                    return false;
                }
            }
            if (num.length() == next.length())
            {
                return true;
            }
            else
            {
                return isAdditiveNumber(num.substr(next.length(), num.length() - next.length()), pre2, next);
            }
        }
    }

    string sum(string num1, string num2)
    {
        string ans = string(max(num1.length(), num2.length()),'0');
        int t = 0;
        if (num1.length() < num2.length())
        {
            num1 = string(num2.length() - num1.length(),'0') + num1;
        }
        else if (num1.length() > num2.length())
        {
            num2 = string(num1.length() - num2.length(), '0') + num2;
        }

        for (int i = ans.length() - 1; i >= 0; i--)
        {
            int n1 = num1[i] - '0';
            int n2 = num2[i] - '0';

            ans[i] = (n1 + n2 + t) % 10 + '0';
            t = (n1 + n2 + t) / 10;
        }
        if (t != 0)
        {
            ans = '1' + ans;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.isAdditiveNumber("198019823962") << endl;
}