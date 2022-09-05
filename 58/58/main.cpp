#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int index = 0;
        while (index < s.size())
        {
            int l = 0;
            while(index < s.size() && s[index] != ' ')
            {
                index += 1;
                l += 1;
            }
            ans = l;
            while (index < s.size() && s[index] == ' ')
            {
                index += 1;
            }
        }
        return ans;
    }
};