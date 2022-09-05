#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int isToken[256] = { 0 };
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
                    return false;
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
    string s = "      a";
    cout << solution.isPalindrome(s) << endl;
}