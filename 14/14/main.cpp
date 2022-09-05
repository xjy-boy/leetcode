#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int j = 0;
        for (int i = 1; i < strs.size(); i++)
        {
            for (j = 0; j < min(prefix.size(), strs[i].size());j++)
            {
                if (prefix[j] != strs[i][j])
                {
                    break;
                }
            }
            if (j == 0)
            {
                return "";
            }
            else
            {
                prefix = prefix.substr(0, j);
            }
        }
        return prefix;
    }
};