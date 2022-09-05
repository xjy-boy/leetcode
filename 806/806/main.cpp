#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int row = 0;
        int now = 0;
        for (char c : s)
        {
            now += widths[c - 'a'];
            if (now > 100)
            {
                row += 1;
                now = widths[c - 'a'];
            }
        }
        if (now != 0)
        {
            row += 1;
        }
        return { row,now };
    }
};

int main()
{

}