#include<iostream>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int num = 0;
        int left = 0;
        int now = 0;
        for (char& c : s)
        {
            if (c == '1')
            {
                num += 1;
            }
        }
        s.pop_back();
        for (char& c : s)
        {
            if (c == '1')
            {
                num -= 1;
            }
            else
            {
                left += 1;
            }
            now = left + num;
            if (now > ans)
            {
                ans = now;
            }
        }
        return ans;
    }
};