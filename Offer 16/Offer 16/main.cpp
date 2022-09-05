#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double temple[32] = { 0 };
        if (n == -2147483648)
        {
            double ans = 1 / x;
            for (int i = 0; i < 5; i++)
            {
                ans *= ans;
            }
            return ans;
        }
        else if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }

        double ans = 1;
        for (int i = 0; i < 32; i++)
        {
            int now = 1 << i;
            if (now > n)
            {
                break;
            }
            if (i == 0)
            {
                temple[i] = x;
            }
            else
            {
                temple[i] = temple[i - 1] * temple[i - 1];
            }
            if (n & now)
            {
                ans *= temple[i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2, -2) << endl;
}