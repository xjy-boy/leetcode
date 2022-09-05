#include<iostream>

using namespace std;


class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = sqrt(c);
        long l2 = 0;
        long r2 = 0;
        long sum = 0;
        while (left <= right)
        {
            l2 = left * left;
            r2 = right * right;
            sum = l2 + r2;
            if (sum == c)
            {
                return true;
            }
            //ÐèÒªÒÆ¶¯right
            else if (sum > c)
            {
                right = min((long)sqrt(c - l2), right - 1);
            }
            else
            {
                left = max((long)sqrt(c - r2), left + 1);
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    s.judgeSquareSum(3);
}