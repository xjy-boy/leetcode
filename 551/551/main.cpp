#include<iostream>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int pre = 0;
        int absent = 0;
        for (char &c : s)
        {
            if (c == 'A')
            {
                absent += 1;
                pre = 0;
                if (absent == 2)
                {
                    return false;
                }
            }
            else if (c == 'L')
            {
                pre += 1;
                if (pre == 3)
                {
                    return false;
                }
            }
            else if (c == 'P')
            {
                pre = 0;
            }
        }
        return true;
    }
};

