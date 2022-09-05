#include<iostream>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        string prefix = "";
        if (num == 0)
        {
            return "0";
        }
        else if (num < 0)
        {
            prefix = "-";
            num = -num;
        }
        while (num != 0)
        {
            char next = num % 7 + '0';
            ans.insert(ans.begin(), next);
            num = num / 7;
        }
        return prefix + ans;
    }
};


int main()
{
    Solution s;
    cout << s.convertToBase7(-7) << endl;
}