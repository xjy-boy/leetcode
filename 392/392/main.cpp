#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())
        {
            return true;
        }
        else if (t.empty())
        {
            return false;
        }
        int pre = -1;
        for (int i = 0; i < s.size(); i++)
        {
            int next = -1;
            for (int j = pre + 1; j < t.size(); j++)
            {
                if (t[j] == s[i])
                {
                    next = j;
                    break;
                }
            }
            if (next < 0)
            {
                return false;
            }
            else
            {
                pre = next;
            }
        }
        
        return true;
    }
};

int main()
{
    string s = "acb";
    string t = "ahbgdc";
    Solution solution;
    solution.isSubsequence(s, t);
}