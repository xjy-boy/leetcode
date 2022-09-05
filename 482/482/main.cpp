#include<iostream>

using namespace std;


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int index = s.size();
        int pre = 0;
        char c = ' ';
        while (index > 0)
        {
            index -= 1;
            if (s[index] == '-')
            {
                continue;
            }
            else if (s[index] >= 'a' && s[index] <= 'z')
            {
                c = s[index] - 32;
            }
            else
            {
                c = s[index];
            }
            if (pre == k)
            {
                ans += '-';
                pre = 1;
            }
            else
            {
                pre += 1;
            }

            ans += c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "2-5g-3-J";
    cout << solution.licenseKeyFormatting(s, 2) << endl;
}