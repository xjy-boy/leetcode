#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() < 2)
        {
            return s;
        }
        vector<int> next = vector<int>(s.size() / 2, 0);

        //KMP算法求解next数组
        next[0] = -1;
        int j = 0;
        int k = -1;
        while (j < next.size() - 1)
        {
            if (k == -1 || s[j] == s[k])
            {
                next[++j] = ++k;
            }
            else
            {
                k = next[k];
            }
        }
    

        //改进的KMP算法，对next数组进行优化
        /*
        for (int i = 1; i < next.size(); i++)
        {
            if (next[i] != 0 && s[i] == s[next[i]])
            {
                next[i] = next[next[i]];
            }
        }*/

        //进行匹配，寻找最长的回文子串
        int index1 = s.size() - 1;
        int index2 = 0;
        while (index1 > index2 * 2)
        {
            if (index2 == -1 || s[index2] == s[index1 - index2])
            {
                index2 += 1;
            }
            else
            {
                index1 = index1 - index2 + next[index2];
                index2 = next[index2];
            }
        }
        string ans = "";
        for (int i = s.size()-1; i > index1; i--)
        {
            ans += s[i];
        }
        return ans + s;
    }
};

int main()
{
    Solution s;
    cout << s.shortestPalindrome("babbbabbaba") << endl;
}