#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<string> ans;
    string s;
    string temple;
public:
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        temple = "";
        ans.clear();
        backtrack(0, 0);
        return ans;
    }

    void backtrack(int index,int now)
    {
        if (now == 4)
        {
            if (index == s.length())
            {
                temple.pop_back();
                ans.emplace_back(temple);
            }
        }
        if (s.length() - index > 3 * (4 - now))
        {
            return;
        }
        int oldLength = temple.length();
        int num = 0;
        string old = temple;
        if (s[index] == '0')
        {
            temple += '0';
            temple += '.';
            backtrack(index + 1, now + 1);
            temple = old;
        }
        else
        {
            int end = (index + 3) < (s.size() - 1) ? (index + 3) : (s.size() - 3 + now);
            for (int i = index; i < end; i++)
            {
                num = num * 10 + s[i] - '0';
                if (num > 255)
                {
                    break;
                }
                else
                {
                    temple += s.substr(index, i - index + 1);
                    temple += ".";
                    backtrack(i + 1, now + 1);
                    temple = old;
                }
            }
        }
    }
};

int main()
{
    string s = "10203040";
    Solution solution;
    solution.restoreIpAddresses(s);
}