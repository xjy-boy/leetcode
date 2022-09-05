#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    string reformat(string s) {
        int index1 = 0;
        int index2 = 0;

        string ans = "";
        bool isEnd = false;

        while (!isEnd && (index1 < s.size()
            || index2 < s.size()))
        {
            while (index1 < s.size()
                && s[index1] >= 'a')
            {
                index1 += 1;
            }

            while (index2 < s.size()
                && s[index2] < 'a')
            {
                index2 += 1;
            }

            if (index1 < s.size() && index2 < s.size())
            {
                ans = ans + s[index1] + s[index2];
            }
            else if (index1 < s.size())
            {
                ans = ans + s[index1];
                isEnd = true;
            }
            else if (index2 < s.size())
            {
                ans = s[index2] + ans;
                isEnd = true;
            }
            index1 += 1;
            index2 += 1;
        }
        if (ans.size() == s.size())
        {
            return ans;
        }
        else
        {
            return "";
        }
    }
};

int main()
{
    Solution so;
    string s = "covid2019";
    cout << so.reformat(s) << endl;
}