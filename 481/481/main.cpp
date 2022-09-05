#include<iostream>

using namespace std;


class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int index = 2;
        int ans = 1;
        while (s.size() < n)
        {
            if (s.back() == '2')
            {
                if (s[index] == '2')
                {
                    s += "11";
                    ans += 2;
                }
                else
                {
                    s += "1";
                    ans += 1;
                }
            }
            else
            {
                if (s[index] == '2')
                {
                    s += "22";
                }
                else
                {
                    s += "2";
                }
            }
            index += 1;
        }
        if (n < s.size() && s.back() == '1')
        {
            ans -= 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.magicalString(7) << endl;
}