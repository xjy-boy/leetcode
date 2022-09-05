#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string temple = "#";
        for (char c : s)
        {
            temple += c;
            temple += "#";
        }

        int right = 0;
        int center = 0;
        int ansCenter = 0;
        int ansLength = 0;
        vector<int> dp = vector<int>(temple.size(),0);
        for (int i = 0; i < temple.size(); i++)
        {
            int length = 1;
            if (i < right)
            {
                length = min(right - i, dp[2 * center - i]);
            }
            while (i + length < temple.size() && i - length>=0 && temple[i-length] == temple[i+length])
            {
                length += 1;
            }
            if (length > ansLength)
            {
                ansLength = length;
                ansCenter = i;
            }
            if (i + length > right)
            {
                right = i + length;
                center = i;
            }
            dp[i] = length;
        }
        return s.substr((ansCenter - ansLength + 1) / 2, ansLength - 1);
    }
};

int main()
{
    Solution solution;
    string s = "aacabdkacaa";
    cout << solution.longestPalindrome(s) << endl;
}