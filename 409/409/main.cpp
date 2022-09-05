#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count = vector<int>(52, 0);
        int num = 0;
        for (char c : s)
        {
            int index = 0;
            if (c >= 'a')
            {
                index = c - 'a';
            }
            else
            {
                index = c - 'A' + 26;
            }
            count[index] += 1;
            if (count[index] % 2 == 0)
            {
                num -= 1;
            }
            else
            {
                num += 1;
            }
        }
        if (num == 0)
        {
            num = 1;
        }
        return s.size() - num + 1;
    }
};

int main()
{
    Solution solution;
    string s = "abccccdd";
    cout << solution.longestPalindrome(s) << endl;
}