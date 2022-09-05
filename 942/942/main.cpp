#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int min = 0;
        int max = s.size();
        vector<int> ans = vector<int>(s.size() + 1, 0);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
            {
                ans[i] = min;
                min += 1;
            }
            else
            {
                ans[i] = max;
                max -= 1;
            }
        }
        ans[s.size()] = min;
        return ans;
    }
};