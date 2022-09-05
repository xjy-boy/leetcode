#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                start = i;
                break;
            }
        }
        vector<int> ans;
        for (int i = 0; i < start; i++)
        {
            ans.emplace_back(start - i);
        }
        int index = start;
        int pre = start;
        while (index < s.size())
        {
            if (s[index] != c)
            {
                ans.emplace_back(index - pre);
            }
            else
            {
                ans.emplace_back(0);
                for (int i = (index + pre) / 2 + 1; i < index; i++)
                {
                    ans[i] = index - i;
                }
                pre = index;
            }
            index += 1;
        }
        return ans;
    }
};