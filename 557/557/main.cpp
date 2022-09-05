#include<iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int index = 0;
        int start = 0;
        int end = 0;
        char c = ' ';
        while (index < s.size())
        {
            start = index;

            while (index < s.size() && s[index] != ' ')
            {
                index += 1;
            }
            end = index - 1;
            while (start < end)
            {
                c = s[start];
                s[start] = s[end];
                s[end] = c;
                start += 1;
                end -= 1;
            }
            index += 1;
        }
        return s;
    }
};