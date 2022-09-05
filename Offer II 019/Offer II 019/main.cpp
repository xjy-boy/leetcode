#include<iostream>

using namespace std;

class Solution {
public:
    int isToken[256] = { 0 };
    Solution()
    {
        for (int i = '0'; i < '9' + 1; i++)
        {
            isToken[i] = 1;
        }
        for (int i = 'a'; i < 'z' + 1; i++)
        {
            isToken[i] = 2;
        }
        for (int i = 'A'; i < 'Z' + 1; i++)
        {
            isToken[i] = 3;
        }
    }
    bool isPalindrome(string s) {
        return palindrome(s, 1);
    }

    bool palindrome(string s, int n)
    {
        int left = 0;
        int right = s.size() - 1;


        while (left < right)
        {
            while (left < right && !isToken[s[left]])
            {
                left += 1;
            }
            while (right > left && !isToken[s[right]])
            {
                right -= 1;
            }
            if (left != right)
            {
                if (isToken[s[left]] == 3)
                {
                    s[left] += 32;
                }
                if (isToken[s[right]] == 3)
                {
                    s[right] += 32;
                }
                if (s[left] != s[right])
                {
                    if (n == 0)
                    {
                        return false;
                    }
                    else
                    {
                        return palindrome(s.substr(left, right - left), n - 1) || palindrome(s.substr(left + 1, right - left), n - 1);
                    }
                }
                left += 1;
                right -= 1;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution = Solution();
    string s = "aacaab";
    cout << solution.isPalindrome(s) << endl;
}