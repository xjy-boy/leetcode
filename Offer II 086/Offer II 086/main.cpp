#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> length;
    vector<vector<string>> ans;
    vector<string> now;
public:
    vector<vector<string>> partition(string s) {
        //Ê×ÏÈ¼ÆËãlength
        manacher(s);
        ans.clear();
        now.clear();
        backtrack(0, s);
        return ans;
    }

    void backtrack(int nowIndex,string s)
    {
        if (nowIndex >= s.length())
        {
            ans.emplace_back(now);
            return;
        }
        for (int i = nowIndex; i < s.length(); i++)
        {
            if (isPalindromic(nowIndex, i))
            {
                now.emplace_back(s.substr(nowIndex, i - nowIndex + 1));
                backtrack(i + 1, s);
                now.pop_back();
            }
        }
    }

    vector<int> manacher(string s)
    {
        string templeS = "#";
        for (char c : s)
        {
            templeS += c;
            templeS += '#';
        }
        length = vector<int>(templeS.length(), 1);
        int maxi = 1;
        int maxLeft = 2;
        for (int i = 1; i < templeS.length(); i++)
        {
            int nowLength = 1;
            if (i < maxLeft)
            {
                nowLength = min(maxLeft - i + 1, length[2 * maxi - maxLeft]);
            }
            while (i + nowLength < templeS.length() && i - nowLength >= 0)
            {
                if (templeS[i + nowLength] == templeS[i - nowLength])
                {
                    nowLength += 1;
                }
                else
                {
                    break;
                }
            }
            length[i] = nowLength;
        }
        return length;
    }

    bool isPalindromic(int i, int j)
    {
        return (length[i + j + 1]  - 2) >= (j - i);
    }
};

int main()
{
    string s = "aab";
    Solution solution;
    solution.partition(s);
}