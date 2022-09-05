#include<iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if (n == 0)
        {
            return 0;
        }
        n -= 1;
        int length = 1;
        int num = 9;
        int start = 1;
        while (n/length >= num)
        {
            start += num;
            n -= num * length;
            num *= 10;
            length += 1;
        }

        int number = n / length + start;
        int bit = pow(10, length - n % length - 1);
        return (number /bit) % 10;
    }
};

int main()
{
    Solution s;
    //cout << s.findNthDigit(10) << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << s.findNthDigit(i);
    }
}