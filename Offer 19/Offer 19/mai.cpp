#include<iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
        {
            return s.empty();
        }
        int now = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (i < p.size() -1  && p[i+1] == '*')
            {
                //*²»Æ¥Åä×Ö·û
                if (isMatch(s.substr(now, s.length() - now), p.substr(i + 2, p.length() - i - 2)))
                {
                    return true;
                }
                //*Æ¥Åä×Ö·û
                while (now < s.size() && (p[i] == '.' || p[i] == s[now]))
                {
                    now += 1;
                    if (isMatch(s.substr(now, s.length() - now), p.substr(i + 2, p.length() - i - 2)))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                if (now == s.size())
                {
                    return false;
                }
                else if (p[i] != '.' && p[i] != s[now])
                {
                    return false;
                }
                now += 1;
            }
        }

        return now == s.size();
    }
};

int main()
{
    string s = "aab";
    string p = "c*a*b";
    Solution solution;
    cout << solution.isMatch(s, p) << endl;
}