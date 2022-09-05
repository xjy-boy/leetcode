#include<iostream>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        char symbol[5][2] =
        {
            {'A','A'},
            {'M','M'},
            {'C','D'},
            {'X','L'},
            {'I','V'},
        };
        int now = 1000;
        for (int i = 1; i < 5; i++)
        {
            int t = num / now;
            num = num % now;
            now = now / 10;
            if (t == 0)
            {
                continue;
            }
            else if (t == 9)
            {
                ans += symbol[i][0];
                ans += symbol[i - 1][0];
                continue;
            }
            else if (t == 4)
            {
                ans += symbol[i][0];
                ans += symbol[i][1];
                continue;
            }
            else if (t >= 5)
            {
                ans += symbol[i][1];
                t -= 5;
            }

            for (int j = 0; j < t; j++)
            {
                ans += symbol[i][0];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(2000) << endl;
}