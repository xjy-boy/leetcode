#include<iostream>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1)
        {
            return 1;
        }
        else
        {
            return 2 * lastRemainingRight(n / 2);
        }
    }

    int lastRemainingRight(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        else if (n % 2 == 0)
        {
            return 2 * lastRemaining(n / 2) - 1;
        }
        else
        {
            return 2 * lastRemaining(n / 2);
        }
    }
};

int main()
{
    Solution s;
    cout << s.lastRemaining(12) << endl;
}