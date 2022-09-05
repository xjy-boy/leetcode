#include<iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int left = 0;
        int right = k;
        int start = 0;
        int length = s.length();
        char t = ' ';
        while (start < s.size())
        {
            left = start;
            right = min(length - 1, start + k - 1);
            while (left < right)
            {
                t = s[left];
                s[left] = s[right];
                s[right] = t;
                left += 1;
                right -= 1;
            }
            start = start + 2 * k;
        }
        return s;
    }
};

int main()
{
    Solution s;
    string input = "abcdefg";
    cout << s.reverseStr(input, 8) << endl;
}