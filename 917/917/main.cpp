#include<iostream>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (!(s[left] <= 'z' && s[left] >= 'a') && !(s[left] <= 'Z' && s[left] >= 'A') && left < right)
            {
                left += 1;
            }
            while (!(s[right] <= 'z' && s[right] >= 'a') && !(s[right] <= 'Z' && s[right] >= 'A') && left < right)
            {
                right -= 1;
            }

            char t = s[right];
            s[right] = s[left];
            s[left] = t;
            right -= 1;
            left += 1;
        }
        return s;
    }
};

int main()
{
    Solution solution = Solution();
    string s = "a-bC-dEf-ghIj";
    cout << solution.reverseOnlyLetters(s) << endl;
}