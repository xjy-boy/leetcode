#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index1 = 0;
        int index2 = 0;
        int ans = 0;
        while (index1 < g.size() && index2 < s.size()) 
        {
            if (s[index2] >= g[index1]) 
            {
                ans += 1;
                index1 += 1;
                index2 += 1;
            }
            else
            {
                index2 += 1;
            }
        }
        return ans;
    }
};