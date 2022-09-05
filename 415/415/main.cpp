#include<iostream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int t = 0;
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        while (index1 >= 0 && index2 >= 0)
        {
            int next = num1[index1] - '0' + num2[index2] - '0' + t;
            ans += next % 10 + '0';
            t = next / 10;
            index1 -= 1;
            index2 -= 1;
        }
        if (num1.size() != num2.size())
        {
            
            if (num1.size() > num2.size())
            {
                for (int i = num2.length(); i < num1.size(); i++)
                {
                    int next = num1[num1.length() - i - 1] - '0' + t;
                    ans += next % 10 + '0';
                    t = next / 10;
                }
            }
            else
            {
                for (int i = num1.length(); i < num2.size(); i++)
                {
                    int next = num2[num2.length() - i - 1] - '0' + t;
                    ans += next % 10 + '0';
                    t = next / 10;
                }
            }
        }

        if (t != 0)
        {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    string num1 = "11";
    string num2 = "123";
    cout << s.addStrings(num1, num2) << endl;
}