#include<iostream>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < goal.size(); j++)
            {
                if (goal[j] != s[(j + i) % s.size()])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
        return false;
    }
};