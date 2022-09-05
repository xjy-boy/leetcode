#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        string t = "#";
        for (int i = 0; i < s.size(); i++)
        {
            t += s[i];
            t += '#';
        }
        vector<int> f = vector<int>(t.size(), 0);
        int iMax = 0;
        int rMax = 0;
        int result = 0;
        for (int i = 0; i < t.size(); i++)
        {
            f[i] = i > rMax ? 0 : min(f[2 * iMax - i] - 1, rMax - i - 1);
            while (true)
            {
                f[i] += 1;
                if (i - f[i] >= 0 && i + f[i] < t.size())
                {
                    if (t[i - f[i]] != t[i + f[i]])
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (i + f[i] - 1 > rMax)
            {
                rMax = i + f[i] - 1;
                iMax = i;
            }
            result += f[i] / 2;
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    string s1 = "abc";
    string s2 = "aba";
    string s3 = "a";
    //cout << solution.countSubstrings(s1) << endl;
    cout << solution.countSubstrings(s2) << endl;
    //cout << solution.countSubstrings(s3) << endl;
}