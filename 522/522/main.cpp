#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string str1, string str2) {
            return str1.length() > str2.length();
        });
        int index1 = 0;
        int index2 = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            bool isUS = true;
            for (int j = 0; j < strs.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                else if (!isUS || strs[j].length() < strs[i].size())
                {
                    break;
                }
                index1 = 0;
                index2 = 0;
                while (index1 < strs[j].size() && index2 < strs[i].size())
                {
                    if (strs[j][index1] == strs[i][index2])
                    {
                        index1 += 1;
                        index2 += 1;
                    }
                    else
                    {
                        index1 += 1;
                    }
                }
                isUS = (index2 != strs[i].size());
            }
            if (isUS)
            {
                return strs[i].size();
            }
        }

        return -1;
    }
};

int main()
{
    vector<string> strs = { "aaaa", "aaaa", "aaa","aa" };
    Solution s;
    cout << s.findLUSlength(strs) << endl;
}