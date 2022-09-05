#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        int length = 1;
        int numLength = 1;
        while (x / length >= 10)
        {
            numLength += 1;
            length *= 10;
        }
        for (int i = 0; i < numLength / 2; i++)
        {
            int left = x / length;
            int right = x % 10;
            if (left != right)
            {
                return false;
            }
            else
            {
                x -= left * length;
                x = x / 10;
                length = length / 100;
            }
        }
        
        return true;
    }
};

int main()
{
    Solution s;
    s.isPalindrome(9999);
}