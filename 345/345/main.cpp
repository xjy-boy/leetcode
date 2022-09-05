#include<iostream>

using namespace std;


class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < right)
            {
                if (s[left] == 'a' ||
                    s[left] == 'e' ||
                    s[left] == 'i' ||
                    s[left] == 'o' ||
                    s[left] == 'u' ||
                    s[left] == 'A' ||
                    s[left] == 'E' ||
                    s[left] == 'I' ||
                    s[left] == 'O' ||
                    s[left] == 'U')
                {
                    break;
                }
                else
                {
                    left += 1;
                }
            }

            while (left < right)
            {
                if (s[right] == 'a' ||
                    s[right] == 'e' ||
                    s[right] == 'i' ||
                    s[right] == 'o' ||
                    s[right] == 'u' ||
                    s[right] == 'A' ||
                    s[right] == 'E' ||
                    s[right] == 'I' ||
                    s[right] == 'O' ||
                    s[right] == 'U')
                {
                    break;
                }
                else
                {
                    right -= 1;
                }
            }

            char c = s[left];
            s[left] = s[right];
            s[right] = c;
            left += 1;
            right -= 1;
        }
        return s;
    }
};